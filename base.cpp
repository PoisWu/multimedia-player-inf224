#include "base.h"
#include <iostream>

Base::Base(){
    this->filename="";
    this->file_path="";
}

Base::Base(std::string _filename, std::string _file_path){
    this->filename = _filename;
    this->file_path = _file_path;
}

std::string Base::get_filename() const{
    return this->filename;
}

std::string Base::get_file_path() const{
    return this->file_path;
}

void Base::set_filename(std::string _filename){
    this->filename = _filename;
}

void Base::set_file_path(std::string _file_path){
    this->file_path = _file_path;
}

void Base::print(std::ostream & out_stream) const{
    out_stream << "FileName:\t" << this->filename << std::endl 
        << "File Path:\t" << this->file_path << std::endl;
}



