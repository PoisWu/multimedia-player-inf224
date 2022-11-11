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
        ~Photo();
        double get_latitude() const;
        double get_longitude() const;
        void set_latitude(double _latitude);
        void set_longitude(double _longitude);
        void print(std::ostream&) const override;
        void run() const override;
};

using photoPtr = std::shared_ptr<Photo>;

#endif //PHOTO_H
