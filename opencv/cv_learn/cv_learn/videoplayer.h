#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>

class VideoPlayer{

public:
    VideoPlayer();
    ~VideoPlayer();

public:
    int Play(char *video_path);
    int CameraPlay();
    int ScaleVideo(char *video_src_path,  char *video_dst_path);

private:
//static void onTrackbarSlide(int pos);

private:
    CvCapture *camera_capture;

};


#endif // VIDEOPLAYER_H
