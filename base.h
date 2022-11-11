#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <memory>
#include <string> 


class Base{
    private:
        std::string filename; // the name of object multmédia
        std::string file_path; // The absolute path of object mulimédia
        
    public:
        Base();
        virtual ~Base();

        /// Constructeur
        /// @param _filename The filename of object
        /// @param _file_path The path of oject
        Base(std::string _filename, std::string _file_path);//With argument

        /// Getting the  filename of object
        /// @return the filename of associated object
        std::string get_filename() const;
        
        /// Getting the  file Path  of object
        /// @return the filename of associated object
        std::string get_file_path() const;

        /// Set the filename of object 
        /// @param _filename 
        void set_filename(std::string _filename);

        /// Set the path of object 
        /// @param _file_path
        void set_file_path(std::string _file_path) ;

        /// Print the detail of object
        /// @param the output stream (For example `std::cout`)
        virtual void print(std::ostream &)const;

        /// @brief "Play" the object
        virtual void run() const=0;
};

using basePtr = std::shared_ptr<Base>;
#endif //BASE_H
