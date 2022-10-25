#ifndef GESTION_H
#define GESTION_H

#include <map>
#include <string>
#include "group.h"
#include "base.h"


class Gestion{
    private:
        std::map<std::string, groupPtr> tab_group;
        std::map<std::string, basePtr> tab_base;

    public:
        Gestion();




};



#endif //GESTION_H
