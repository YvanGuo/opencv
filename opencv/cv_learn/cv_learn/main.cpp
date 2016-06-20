#include "mainwindow.h"
#include <QApplication>
#include "videoplayer.h"
#include "img_proc.h"
#include <QDebug>
#include <stdio.h>
#include <vector>
using namespace cv;
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //VideoPlayer player;
    //player.Play("tree.avi");

    Img_proc imgproc;
    int x = 200;
    int y = 200;
    int wd = 100;
    int height = 100;
    int add = 100;
    IplImage* image;
    Mat image1;
    Mat image2;
    Mat imageROI;
    Mat dst;
    IplImage* tmp;
    CvRect rect;
    vector<Mat> channels;

    //image = cvLoadImage("lena.jpg");
    //cvSetImageROI(image, cvRect(x,y,wd,height));
    //tmp = imgproc.smooth(image);
    //cvAddS(image, cvScalar(add), image);
    //cvResetImageROI(image);
    //cvNamedWindow("show ROI", 1);
    //cvShowImage("show ROI", image);

    image1 = imread("puzzle.png");
    image2 = imread("JCB.png");

//    cvtColor(image1, dst, COLOR_BGR2GRAY);

#if 0
    imageROI = image1(Rect(10,10,image2.cols, image2.rows));
    x = image1.channels();
    y = image2.channels();
    qDebug("open .lena.jpg %d\n", image1.channels());
    qDebug("open JCB.png %d \n", image2.channels());
    if(!image1.data){

        qDebug("open lena.jpg erro");

    }
    if(!image2.data){

        qDebug("open puzzle.png erro");

    }



    Mat dstimg = image2;

    addWeighted(imageROI, (double)0.7, image2, (double)0.3, (double)0.0, imageROI);
#endif


#if 0
    split(image1, channels);
    dst = channels.at(0);

    namedWindow("misc show0", 1);
    imshow("misc show0", dst);

    dst = channels.at(1);
    namedWindow("misc show1", 1);
    imshow("misc show1", dst);

    dst = channels.at(2);
    namedWindow("misc show2", 1);
    imshow("misc show2", dst);


    merge(channels, dst);

    namedWindow("misc show4", 1);
    imshow("misc show4", dst);
#endif

    imgproc.set_bright(150, 10, "puzzle.png");
    return a.exec();
}
