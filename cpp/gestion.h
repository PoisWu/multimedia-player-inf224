#ifndef GESTION_H
#define GESTION_H

#include <map>
#include <string>
#include "group.h"
#include "base.h"
#include "film.h"
#include "photo.h"
#include "video.h"
#include <iostream>

/// @file gestion.h
/// @brief class Gestion provide a detail structure of object photo 
/// @author Cheng-Yen Wu
/// @date 2022

class Gestion{
    private:
        std::map<std::string, groupPtr> tab_group;
        std::map<std::string, basePtr> tab_base;

    public:
        /// @fn Gestion()
        /// @brief Construtor 
        Gestion();

        /// @fn photoPtr create_photo(double _latitude, double _longitude, std::string _filename, std::string _file_path);
        /// @brief creat the photo object and put in the tab_base
        /// @return a smart ponter of photo that point to the photo object
        photoPtr create_photo(double _latitude, double _longitude, 
                std::string _filename, std::string _file_path);

        /// @fn videoPtr create_video(int _v_duration, std::string _filename, std::string _file_path);
        /// @brief creat the video object and put in the tab_base
        /// @return a smart ponter of video that point to the video object
        videoPtr create_video(int _v_duration, std::string _filename, 
                std::string _file_path);

        /// @fn filmPtr create_film(int nb_chapiter, int _video_duration, std::string _filename, std::string _file_path);
        /// @brief creat the film object and put in the tab_base
        /// @return a smart ponter of film that point to the film object
        filmPtr create_film(int nb_chapiter, int _video_duration, 
                std::string _filename, std::string _file_path);

        /// @fn groupPtr create_group(std::string group_name)
        /// @brief creat the group object and put in the tab_group
        /// @return a smart ponter of group that point to the group object
        groupPtr create_group(std::string group_name);

        /// @fn void print(std::ostream& out_stream, std::string name) const
        /// @brief print the detail of `name` object 
        /// If no `name` object in the database, it print `name` not found!
        /// Otherwise, it print the detail information of object `name`
        /// @param out_stream       example `std::out`
        /// @param name             look up the "name" object in the database
        void print(std::ostream& out_stream, std::string name) const;
        

        // print error if non object found
        /// @fn void play(std::string filename) const
        /// @brief run the multimedia object 
        /// @param filemanem        the filename of mutimedia object
        void play(std::string filename) const;

        /// @fn void delete_object(std::string filename)
        /// @brief delete the `filename` object in the database
        /// @param filename         the filename of target object.
        void delete_object(std::string filename);

        /// @fn void delete_group(std::string group_name)
        /// @brief  delete the `group_name` group in the database
        /// @param group_name       The group_name of target group 
        void delete_group(std::string group_name);
};

#endif //GESTION_H
