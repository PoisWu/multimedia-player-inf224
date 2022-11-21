#include "gestion.h"
#include <memory>

Gestion::Gestion(){



}

photoPtr Gestion::create_photo(double _latitude, double _longitude, 
        std::string _filename, std::string _file_path){
    photoPtr ptr(new Photo(_latitude,_longitude, _filename, _file_path));
    tab_base.insert(make_pair(_filename, ptr));
    return ptr;
}
videoPtr Gestion::create_video(int _v_duration, std::string _filename, 
        std::string _file_path){
    videoPtr ptr(new Video(_v_duration, _filename, _file_path));
    tab_base.insert(make_pair(_filename, ptr));
    return ptr;
}
filmPtr Gestion::create_film(int nb_chapiter, int _video_duration, 
        std::string _filename, std::string _file_path){
    filmPtr ptr(new Film(nb_chapiter, _video_duration,_filename, _file_path));
    tab_base.insert(make_pair(_filename, ptr));
    return ptr;
}
groupPtr Gestion::create_group(std::string group_name){
    groupPtr ptr(new Group(group_name));
    tab_group.insert(make_pair(group_name, ptr));
    return ptr;
}

// print atributs of object, if not found print error

/* void Gestion::print_base(std::ostream& out_stream, std::string filename) const{ */
/*     auto it_base = tab_base.find(filename); */
/*     if (it_base != tab_base.end()) it_base->second->print(out_stream); */
/*     else out_stream << filename << "is not found" << std::endl; */
/* } */

/* void Gestion::print_group(std::ostream & out_stream, std::string groupname) const{ */
/*     auto it_group = tab_group.find(groupname); */
/*     if (it_group != tab_group.end()) it_group->second->print(out_stream); */
/*     else out_stream << groupname << "is not found" << std::endl; */
/* } */

void Gestion::print(std::ostream &out_stream, std::string name) const{
    auto it_base = tab_base.find(name);
    auto it_group = tab_group.find(name);
    if (it_base != tab_base.end()) it_base->second->print(out_stream);
    else if (it_group != tab_group.end()) it_group->second->print(out_stream);
    else out_stream << name << "is not found" << std::endl;

}

// print error if non object found
void Gestion::play(std::string filename) const{
    auto it_base = tab_base.find(filename);
    if (it_base != tab_base.end()) it_base->second->run();
    else std::cout << filename << " is not found" << std::endl;
}
void Gestion::delete_object(std::string filename){

}
void Gestion::delete_group(std::string group_name){

}
