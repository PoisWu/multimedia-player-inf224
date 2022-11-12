//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "gestion.h"
#include <regex>

const int PORT = 3331;
const std::string media_path="/home/cheng-yen/Documents/X/4A/inf224/tp/media/";

Gestion db = Gestion();
auto pho1 = db.create_photo(11,11, "imag1.jpg", media_path+"imag1.jpg");
auto pho2 = db.create_photo(22,22, "imag2.jpg", media_path+"imag2.jpg");
auto film1 = db.create_film(1, 3, "film1.mp4", media_path+"film1.mp4");
auto gr1 = db.create_group("gr1");



int main(int argc, char* argv[])
{
  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {


    // Setup data base

    // Protocol: 
    // GET name | In order to  find the multimédia or 
    // Play name | In order to play 
    // the request sent by the client to the server

    std::cout << "request: " << request << std::endl;
    /* std::regex find_regex("GET [0-9a-zA-Z\\.]+"); */
    /* std::smatch filename; */
    /* std::regex_search(request, filename, find_regex); */
    /* std::cout << "0: " <<  filename[0] << std::endl; */
    /* std::cout << "1: " <<  filename[1] << std::endl << std::flush; */
    /* std::cout << "2: " <<  filename[2] << std::endl << std::flush; */
    int isget = (request.find("GET ")==0);
    int isplay = (request.find("PLAY ")==0);
    std::stringstream  ss;
    if (isget){
        std::string line;
        db.print(ss, request.substr(4)); 
        while (std::getline(ss, line)){
            response += line;
            response += ";";
        }
    }

    if (isplay) {
        db.play(request.substr(5));
    }


    
    // the response that the server sends back to the client


    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}

