#ifndef PHOTO_H
#define PHOTO_H

#include "base.h"
#include <iostream>


/// @file photo.h
/// @brief class Photo provide a detail structure of object photo 
/// @author Cheng-Yen Wu
/// @date 2022

class Photo: public Base{
    private:
        double latitude{};
        double longitude{};

    public:
        /// @fn Photo 
        /// @brief Defaut constructor
        Photo();

        /// @fn Photo(double _latitude, double _longitude, std::string _filename, std::string _file_path)
        /// @brief constructor 
        /// @param 
        Photo(double _latitude, double _longitude, 
                std::string _filename, std::string _file_path);
        ~Photo();

        /// @fn double get_latitude() const
        /// @brief get the latitude of photo
        /// @return the latitude of photo
        double get_latitude() const;

        /// @fn double get_longitude() const
        /// @brief get the longitude of photo
        /// @return the longitude of photo
        double get_longitude() const;

        /// @fn void set_latitude(double _latitude)
        /// @brief set the latitude of photo
        /// @param _latitude        the latitude value
        void set_latitude(double _latitude);

        /// @fn void set_longitude(double _longitude)
        /// @brief set the longitude of photo
        /// @param _longitude       the longitude value
        void set_longitude(double _longitude);

        /// @fn void print(std::ostream&) const override
        /// @brief print the detail of photo
        /// @param out_stream       the output stream (For example `std::out`)
        void print(std::ostream& out_stream) const override;

        /// @fn void run() const override
        /// @brief Play the photo. 
        void run() const override;
};

using photoPtr = std::shared_ptr<Photo>;

#endif //PHOTO_H
