#ifndef IMG_PROC_H
#define IMG_PROC_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <stdio.h>

class Img_proc{

public:
    Img_proc();
    ~Img_proc();

public:
    IplImage *smooth(IplImage * image, int filter = IPL_DEPTH_8U);
    IplImage *scale(IplImage * image, int filter = CV_GAUSSIAN_5x5);
    IplImage *doCanny(IplImage * image, double lowThresh,double highThreash, double aperture);


};

#endif // IMG_PROC_H
