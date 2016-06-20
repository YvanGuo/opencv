#include "img_proc.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;

Img_proc::Img_proc()
{

}

Img_proc::~Img_proc()
{

}

IplImage * Img_proc::smooth(IplImage * image, int filter)
{

    //cvNamedWindow("smooth Image in", WINDOW_AUTOSIZE );
    //cvNamedWindow("smooth Image out", WINDOW_AUTOSIZE );

    //cvShowImage("smooth Image in", image);

    IplImage *out = cvCreateImage(cvGetSize(image), filter, 3);

    cvSmooth(image, image, CV_GAUSSIAN, 19, 19);

    return out;

    //cvShowImage("smooth Image out", out);

    //waitKey(0);

    //cvReleaseCapture(&out);
    //cvDestroyWindow("smooth Image in");
    //cvDestroyWindow("smooth Image out");

}

IplImage *Img_proc::scale(IplImage * image, int filter)
{

    IplImage *image_out;

    assert(image->width % 2 == 0 && image->height % 2 == 0);

    image_out = cvCreateImage(cvSize(image->width/2, image->height /2),\
                            image->depth,  image->nChannels);
    cvPyrDown(image, image_out);

    return image_out;
}

IplImage *Img_proc::doCanny(IplImage *image, double lowThresh,double highThreash, double aperture)
{
    if(image->nChannels  != 1){

        printf("doCanny only one channel pic\n");
        return 0;
    }

    IplImage *image_out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U,  1);

    cvCanny(image, image_out,lowThresh, highThreash,aperture);

    return image_out;

}

void Img_proc::set_bright(int ctrst, int brt, char *imgpath)
{

    int constra = ctrst;
    int brit = brt;
    Mat g_srcimg = imread(imgpath);
    Mat g_destimg = Mat::zeros(g_srcimg.size(), g_srcimg.type());



    for(int y = 0; y < g_srcimg.rows; y++){

        for(int x = 0; x < g_srcimg.cols; x++){

            for(int c = 0; c < 3; c++){

                g_destimg.at<Vec3b>(y,x)[c] = saturate_cast<uchar>((constra*0.01)*(g_srcimg.at<Vec3b>(y,x)[c]) + brit);

            }

        }

    }

    namedWindow("show set_bright_SRC", 1);
    imshow("show set_bright_SRC", g_srcimg);

    namedWindow("show set_bright_DST", 1);
    imshow("show set_bright_DST", g_destimg);




}
