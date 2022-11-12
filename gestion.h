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


class Gestion{
    private:
        std::map<std::string, groupPtr> tab_group;
        std::map<std::string, basePtr> tab_base;

    public:
        Gestion();
        photoPtr create_photo(double _latitude, double _longitude, 
                std::string _filename, std::string _file_path);
        videoPtr create_video(int _v_duration, std::string _filename, 
                std::string _file_path);
        filmPtr create_film(int nb_chapiter, int _video_duration, 
                std::string _filename, std::string _file_path);
        groupPtr create_group(std::string group_name);

        // print atributs of object, if not found print error
        /* void print_base(std::ostream& out_stream, std::string filename) const; */
        
        /* void print_group(std::ostream& out_stream, std::string groupname) const; */

        void print(std::ostream& out_stream, std::string name) const;
        

        // print error if non object found
        void play(std::string filename) const;

        void delete_object(std::string filename);
        void delete_group(std::string group_name);
};



#endif //GESTION_H
