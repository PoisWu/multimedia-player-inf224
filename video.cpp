#include "video.h"

Video::Video():Base(){
    this->video_duration=0;
}

Video::Video(int  _video_duration, 
        std::string _filename, std::string _file_path):Base(_filename,_file_path){
    this->video_duration=_video_duration;
}

int Video::get_video_duration() const{
    return this->video_duration;
};

void Video::set_video_duration(int  _video_duration){
    this->video_duration=_video_duration;
}

void Video::print(std::ostream & out_stream) const{
    this->Base::print(out_stream);
    out_stream 
        << "Video Duration:\t" << this->video_duration <<std::endl;
}

