#ifndef VIDEO_H
#define VIDEO_H

#include "base.h"
#include <memory> 
#include <iostream>

/// @file video.h
/// @brief class Video provide a detail structure of object video.
/// @author Cheng-Yen Wu
/// @date 2022
class Video:public Base{
    private:
        int video_duration{};
    public:
        /// @fn Video()
        /// @brief defaut constructor
        Video();

        /// @fn Video(int  _video_duration, std::string _filename, std::string _file_path)
        /// @brief  constructor
        /// @param _video_duration      The length of video
        /// @param _filename            The filename of video 
        /// @param _file_path           The path of video
        Video(int  _video_duration, 
                std::string _filename, std::string _file_path);
        /// @fn ~Video()
        /// @param descructor
        ~Video();

        /// @fn int get_video_duration() const
        /// @return  the lenght of video
        /// @brief get the length of video
        int get_video_duration() const;

        /// @fn void set_video_duration(int  _video_duration)
        /// @brief set the length of video 
        /// @param _video_duration      The length of video 
        void set_video_duration(int  _video_duration);

        /// @fn void print(std::ostream &) const override
        /// @brief print the detail of video 
        /// @param out_stream           The output stream (for example `std::out`)
        void print(std::ostream & out_stream) const override;

        /// @fn void run() const override
        /// @brief play the video 
        void run() const override;
};

using videoPtr = std::shared_ptr<Video>;

#endif //VIDEO_H

