#ifndef PHOTO_H
#define PHOTO_H

#include "base.h"
#include <iostream>

class Photo: public Base{
    private:
        double latitude{};
        double longitude{};

    public:
        Photo();
        Photo(double _latitude, double _longitude, 
                std::string _filename, std::string _file_path);
        double get_latitude() const;
        double get_longitude() const;
        void set_latitude(double _latitude);
        void set_longitude(double _longitude);
        void print(std::ostream&) const override;
        void run() const override;
};

Photo::Photo():Base(){
    this->latitude=0;
    this->longitude=0;
}

Photo::Photo(double _latitude, double _longitude, 
        std::string _filename, std::string _file_path):Base(_filename,_file_path) {
    this->latitude=_latitude;
    this->longitude=_longitude;
}

double Photo::get_latitude() const {
    return this->latitude;
}

double Photo::get_longitude() const {
    return this->longitude;
}

void Photo::set_latitude(double _latitude) {
    this->latitude=_latitude;
}

void Photo::set_longitude(double _longitude) {
    this->longitude=_longitude;
}

void Photo::print(std::ostream & out_stream) const{
    this->Base::print(out_stream);
    out_stream 
        << "Latitude & longitude:\t" 
        << this->latitude << ", " << this-> longitude
        << std::endl;
}

void Photo::run() const{
    std::string command = "mpv " + this->get_file_path()+ " &";
    system(command.data());
}

#endif //PHOTO_H
