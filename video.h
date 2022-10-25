#ifndef VIDEO_H
#define VIDEO_H

#include "base.h"
#include <iostream>

class Video:public Base{
    private:
        int video_duration{};
    public:
        Video();
        Video(int  _video_duration, 
                std::string _filename, std::string _file_path);
        ~Video();
        int get_video_duration() const;
        void set_video_duration(int  _video_duration);
        void print(std::ostream &) const override;
        void run() const override;
};



#endif //VIDEO_H

