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
        /// @fn Film()
        /// @brief Defaut constructor 

        Film();
        /// @fn Film(int nb_chapiter, int _video_duration, std::string _filename, std::string _file_path);
        /// @brief constructor 
        /// @param nb_chapiter          number of chapiter of video
        /// @param _video_duration      the length of video 
        /// @param _filename            filename of video 
        /// @param _file_path           path of video 
        Film(int nb_chapiter, int _video_duration, 
                std::string _filename, std::string _file_path);

        /// @fn ~Film()
        /// @brief default destructor 
        ~Film(); 

        /// @fn Film(const Film& from)
        /// @brief copy constructor 
        /// @param from                 the copy object target
        /// @return a copy of from 
        Film(const Film& from);

        /// @fn Film& operator=(const Film& from)
        /// @brief redefine = operator 
        /// @param from                 the copy object target
        /// @return a copy of from  
        Film& operator=(const Film& from);

        /// @fn void print(std::ostream &) const override
        /// @brief print the detail of film
        /// @param out_stream           the outputstream (for example `std::cout`) 
        void print(std::ostream & out_stream ) const override;

        /// @fn void set_chapiter_table(int const* tab, int tab_len)
        /// @brief set up the chapiter table 
        /// @param tab                  a list of int table
        /// @param tab_len              length of list `tab`
        void set_chapiter_table(int const* tab, int tab_len);

        /// @fn int const* get_chapiter_duration_table() const
        /// @brief get the chapiter table 
        /// @return return the chapiter table 
        int const* get_chapiter_duration_table() const;

        /// @fn int get_nb_chapiter() const
        /// @brief get the length of chapiter table 
        /// @return return the length of chapiter table 
        int get_nb_chapiter() const;
};

using filmPtr = std::shared_ptr<Film>;

#endif //FILM_H

