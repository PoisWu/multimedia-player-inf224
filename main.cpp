//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include "base.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "gestion.h"

using namespace std;


/* void test3(){ */
/*     // No longer function because pure virtual function `run` makes `Base` as an */
/*     // abstract class */
/*     Base *base1 = new Base("base1.jpg", "/Path/base1.jpg"); */
/*     base1->print(std::cout); */
/*     Base *base2 = new Base(); */
/*     base2->print(std::cout); */
/*     base2->set_filename("filename.jpg"); */
/*     base2->set_file_path("/Path/filename.jpg"); */
/*     base2->print(std::cout); */
/* } */


string media_path = "/home/cheng-yen/Documents/X/4A/inf224/tp/media/";

void test4(){
    Photo* photo1 = new Photo(0,0,"img1.jpg", media_path+"img1.jpg");
    Video* video1 = new Video(0,"vid1.mp4", media_path+"vid1.mp4");

    photo1->print(cout);
    video1->print(cout);
    photo1->run();
    video1->run();
    delete photo1;
    delete video1;

}

void test5(){
    Base** table_base = new Base*[2];
    table_base[0] = new Photo(12,12, "imag1.jpg", media_path+"img1.jpg"); 
    table_base[1] = new Video(0, "vid1.mp4", media_path+"vid1.mp4");

    table_base[0]->run();
    table_base[1]->run();
    table_base[0]->print(cout);
    table_base[1]->print(cout);
    delete [] table_base;
         
}

void test6(){
    Film* film = new Film(3, 12, "vid1.mp4", media_path+"vid1.mp4");
    int chapiters[3]={1,2,3};
    film->set_chapiter_table(chapiters,3);

    film->print(cout);
    cout << film->get_nb_chapiter() << endl;
    delete film;
}

void test7(){
    // Test Copy  opratior=
    Film film = Film(3, 12, "vid1.mp4", media_path+"vid1.mp4");
    int chapiters[3]={1,2,3};
    film.set_chapiter_table(chapiters,3);

    film.print(cout);
    cout << film.get_nb_chapiter() << endl;


    Film film2 = film;
    int new_chapiters[3]={4,5,6};
    film2.set_chapiter_table(new_chapiters,3);
    film2.set_filename("vid2.mp4");



    film.print(cout);
    film2.print(cout);
    /* delete film2; */

    // Test copy constructor

    cout << "------------" << endl;
    Film film3(film);
    film3.set_chapiter_table(new_chapiters,3);
    film3.print(cout);
    film.print(cout);
    /* delete film; */
    
}

/* void test8(){ */
/*     Group group1 = Group("Photo"); */
/*     group1.push_back(new Photo(12,12, "imag1.jpg", media_path+"img1.jpg")); */
/*     group1.push_back(new Photo(12,12, "imag2.jpg", media_path+"img2.jpg")); */
/*     group1.push_back(new Photo(12,12, "imag3.jpg", media_path+"img3.jpg")); */
/*     group1.push_back(new Film(3, 12, "vid1.mp4", media_path+"vid1.mp4")); */
/*     group1.print(cout); */
/* } */

void test9(){
    shared_ptr<Photo> p1(new Photo(12,12, "imag1.jpg", media_path+"img1.jpg"));
    shared_ptr<Photo> p2(new Photo(12,12, "imag2.jpg", media_path+"img2.jpg"));
    shared_ptr<Photo> p3(new Photo(12,12, "imag3.jpg", media_path+"img3.jpg"));
    shared_ptr<Film> f1(new Film(3, 12, "vid1.mp4", media_path+"vid1.mp4"));
    
    Group group1 = Group("Group1");
    Group group2 = Group("Group2");
    group1.push_back(p1);
    group2.push_back(p1);
    group1.push_back(p2);
    group2.push_back(p2);
    group1.push_back(p3);
    group2.push_back(f1);

    //group1: [p1, p2, p3];
    //group2: [p1, p2, f1];
    group1.remove(p3);
    cout << "p3 reset, should print something" << endl;
    p3.reset();
    group2.remove(p2);
    cout << "p2 reset, should print nothing" << endl;
    p2.reset();
    group1.remove(p2);
    cout << "p2 reset, should print something" << endl;
    p2.reset();

    
}

void test10(){
    Gestion gestion = Gestion();
    auto pho1 = gestion.create_photo(11,11, "imag1.jpg", media_path+"img1.jpg");
    auto pho2 = gestion.create_photo(22,22, "imag2.jpg", media_path+"img2.jpg");
    auto film1 = gestion.create_film(1, 3, "film1.mp4", media_path+"film1.mp4");
    auto gr1 = gestion.create_group("gr1");
    
    std::cout << "---------" << std::endl;
    gestion.print_base(std::cout, "imag1.jpg");
    std::cout << "---------" << std::endl;
    gestion.print_base(std::cout, "film1.mp4");
    std::cout << "---------" << std::endl;
    gestion.print_base(std::cout, "gr1");
    std::cout << "---------" << std::endl;
    gestion.print_group(std::cout, "gr1");
}

int main(int argc, const char* argv[])
{
    /* test4(); */
    /* test7(); */
    /* test8(); */
    test10();

    return 0;
}
