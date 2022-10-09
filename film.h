#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <iostream>

class Film:public Video{
    private:
        int nb_chapiter;
        int* chapiter_duration;
    public:
        ~Film(); 
        Film();
        Film(int nb_chapiter, int _video_duration, 
                std::string _filename, std::string _file_path);
        Film(const Film& from);
        Film& operator=(const Film& from);
        void print(std::ostream &) const override;
        void set_chapiter_duration(int index , int value) ;
        int get_chapiter_duration(int index ) const;
        int get_nb_chapiter() const;
};

#endif //FILM_H

