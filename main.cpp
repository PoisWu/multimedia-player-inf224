//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include "base.h"
#include "video.h"
#include "photo.h"

using namespace std;

int main(int argc, const char* argv[])
{
    Base** table_base = new Base*[3];
    table_base[0] = new Video(12, "a.mp3", "/usr/a.mp3");
    table_base[1] = new Photo(12,12, "a.jpg", "/usr/a.jpg"); 
    table_base[2] = new Base("hi.mp3", "usr/hi.mp3");

    for(int i=0;i<3;i++){
        table_base[i]->print(std::cout);
    }
    delete [] table_base;

    return 0;


}
