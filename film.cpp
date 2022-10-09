#include "film.h"

Film::Film():Video(){
    this->nb_chapiter=0;
    this->chapiter_duration=nullptr;
}

Film::Film(int _nb_chapiter, int _video_duration, 
        std::string _filename, std::string _file_path):Video(_video_duration, 
            _filename, _file_path){
    this->nb_chapiter=_nb_chapiter;
    this->chapiter_duration = new int[_nb_chapiter];
    for(int i=0; i< _nb_chapiter; ++i){
        this->chapiter_duration[i]=-1;
    }
}

Film::~Film(){
    delete[] chapiter_duration;
}

Film::Film(const Film& from):Video(from){
    this->nb_chapiter = from.get_nb_chapiter();
    if(this->nb_chapiter==0){
        this->chapiter_duration=nullptr;
    }else{
        this->chapiter_duration = new int[this->nb_chapiter];
        for(int i=0;i<this->nb_chapiter;++i){
            this->set_chapiter_duration(i, from.get_chapiter_duration(i));
        }
    }
}

Film& Film::operator=(const Film& from){
    Video::operator=(from);
    this->nb_chapiter=from.nb_chapiter;
    delete[] chapiter_duration;
    if(nb_chapiter == 0) chapiter_duration=nullptr;
    else{
        this->chapiter_duration = new int[this->nb_chapiter];
        for(int i=0;i<this->nb_chapiter;++i){
            this->set_chapiter_duration(i, from.get_chapiter_duration(i));
        }
    }
    return *this;
}

void Film::set_chapiter_duration(int index, int value){
    if(index < this->nb_chapiter){
        this->chapiter_duration[index]=value;
    }
}

int Film::get_chapiter_duration(int index) const{
    if(index < this->nb_chapiter){
        return this->chapiter_duration[index];
    }else{
        return -1;
    }
}

int Film::get_nb_chapiter() const{
    return this->nb_chapiter;
}

void Film::print(std::ostream& out_stream) const{
    this->Video::print(out_stream);
    for (int i=0; i<this->nb_chapiter; ++i){
    out_stream 
        << this-> chapiter_duration[i] << " ";
    }
    out_stream << std::endl;
}



