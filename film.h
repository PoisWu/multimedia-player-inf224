#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <iostream>
#include <utility>

class Film:public Video{
    private:
        int nb_chapiter{};
        int* chapiter_duration{};
    public:
        ~Film(); 
        Film();
        Film(int nb_chapiter, int _video_duration, 
                std::string _filename, std::string _file_path);
        Film(const Film& from);
        Film& operator=(const Film& from);
        void print(std::ostream &) const override;
        void set_chapiter_table(int const* tab, int tab_len);
        int const* get_chapiter_duration_table() const;
        int get_nb_chapiter() const;
};

using filmPtr = std::shared_ptr<Film>;

#endif //FILM_H

