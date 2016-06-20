#ifndef DISPLAYIMAGE_H
#define DISPLAYIMAGE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>


class displayimage
{
public:
    displayimage();
    int DisPlayImage(IplImage *img);
};

#endif // DISPLAYIMAGE_H
