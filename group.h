#ifndef GROUP_H
#define GROUP_H
#include "base.h"
#include <list>
#include <string>
#include <iostream>


class Group: public std::list<Base *>{
    private:
        std::string group_name;

    public:
        Group(std::string name);
        std::string get_group_name() const;
        void print(std::ostream &) const;
}; 



#endif //GROUP_H
