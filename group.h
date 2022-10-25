#ifndef GROUP_H
#define GROUP_H
#include "base.h"
#include <list>
#include <string>
#include <iostream>
#include <memory>



class Group: public std::list<basePtr>{
    private:
        std::string group_name;

    public:
        Group(std::string name);
        std::string get_group_name() const;
        void print(std::ostream &) const;
}; 


using groupPtr = std::shared_ptr<Group>;

#endif //GROUP_H
