#include "img_proc.h"

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
