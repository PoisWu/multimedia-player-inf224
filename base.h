#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string> 

class Base{
    private:
        std::string filename; // the name of object multmédia
        std::string file_path; // The absolute path of object mulimédia
        
    public:
        Base();
        virtual ~Base();
        Base(std::string _filename, std::string _file_path);//With argument
        std::string get_filename() const;
        std::string get_file_path() const;
        void set_filename(std::string _filename);
        void set_file_path(std::string _file_path) ;
        virtual void print(std::ostream &)const;
        virtual void run() const=0;
};
#endif //BASE_H
