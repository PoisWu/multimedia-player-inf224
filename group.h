#ifndef GROUP_H
#define GROUP_H
#include "base.h"
#include <list>
#include <string>
#include <iostream>
#include <memory>

/// @file group.h
/// @brief class Group provide a collection struture of multimedia object
/// @author Cheng-Yen Wu
/// @date 2022


class Group: public std::list<basePtr>{
    private:
        std::string group_name;

    public:
        /// @fn Group(std::string name)
        /// @brief Defaut Group constructoer 
        /// @param name         name of the group 
        Group(std::string name);

        /// @fn std::string get_group_name() const
        /// @brief get the name of group 
        /// @return the name of group 
        std::string get_group_name() const;

        /// @fn void print(std::ostream &) const
        /// @brief print the detail of group 
        /// @param out_stream the print the information into outstream for exampele (`std::cout`) 
        void print(std::ostream & out_stream) const;
}; 


using groupPtr = std::shared_ptr<Group>;

#endif //GROUP_H
