#include "displayimage.h"

using namespace cv;

displayimage::displayimage()
{

}

int displayimage::DisPlayImage(IplImage *img)
{

    if ( !img )
    {
        printf("No image data \n");
        return -1;
    }
    cvNamedWindow("Display Image", WINDOW_AUTOSIZE );
    cvShowImage("Display Image", img);

    waitKey(0);

}
