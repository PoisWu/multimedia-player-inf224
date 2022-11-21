#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <memory>
#include <string> 

/// @file base.h 
/// @brief class Base gives the basic structure of mutimedia objects.
/// @author Cheng-Yen Wu
/// @date 2022


class Base{
    private:
        std::string filename; // the name of object multmédia
        std::string file_path; // The absolute path of object mulimédia
        
    public:
        /// @fn Base() 
        /// @brief defaut constructeur
        Base();

        /// @brief Constructeur
        /// @fn Base(std::string _filename, std::string _file_path)
        /// @param _filename The filename of object
        /// @param _file_path The path of oject
        Base(std::string _filename, std::string _file_path);//With argument
        
        /// @fn virtual ~Base()
        virtual ~Base();


        /// @brief Getting the  filename of object
        /// @fn std::string get_filename() const
        /// @return the filename of associated object
        std::string get_filename() const;
        
        /// @fn std::string get_file_path() const
        /// @brief Getting the  file Path  of object
        /// @return the filename of associated object
        std::string get_file_path() const;

        /// @fn void set_filename(std::string _filename)
        /// @brief Set the filename of object 
        /// @param _filename 
        void set_filename(std::string _filename);

        /// @fn void set_file_path(std::string _file_path)
        /// @brief Set the path of object 
        /// @param _file_path
        void set_file_path(std::string _file_path) ;

        /// @brief Print the detail of object
        /// @fn virtual void print(std::ostream &)const;
        /// @param the output stream (For example `std::cout`)
        virtual void print(std::ostream &)const;

        /// @brief "Play" the object
        /// @fn virtual void run() const=0;
        virtual void run() const=0;
};

using basePtr = std::shared_ptr<Base>;
#endif //BASE_H
