#include "group.h"
#include <iostream>

Group::Group(std::string name):std::list<basePtr>(){
    this->group_name  = name;
}

std::string Group::get_group_name() const{
    return this -> group_name;
}

void Group::print(std::ostream & out_stream) const{
    out_stream << "Group name:" << this->get_group_name() <<std::endl;
    for(auto& it : *this ){
        it->print(out_stream);
    }
}
