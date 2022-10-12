//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include "base.h"
#include "photo.h"
#include "film.h"

using namespace std;



void test7(){


}


int main(int argc, const char* argv[])
{
    Base** table_base = new Base*[3];
    table_base[1] = new Photo(12,12, "2.jpg", "/tmp/2.jpg"); 
    table_base[1]->run();
        
    delete [] table_base;

    return 0;


}
