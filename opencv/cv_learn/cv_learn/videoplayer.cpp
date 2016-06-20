#include "videoplayer.h"

using namespace cv;


CvCapture *g_capture;
int g_slider_position;
unsigned long int  cur_pos = 0;

VideoPlayer::VideoPlayer()
{
    g_capture = NULL;
    g_slider_position = 0;
    camera_capture = NULL;
}

VideoPlayer::~VideoPlayer()
{

    cvReleaseCapture(&g_capture);
    cvDestroyWindow("Play video");

}



void onTrackbarSlide(int pos)
{

    cur_pos = pos;

    printf("pos = %d\n", pos);
    cvSetCaptureProperty(
        g_capture,
        CV_CAP_PROP_POS_FRAMES,
        pos
    );

}

int VideoPlayer::Play(char *video_path)
{

    int one_per = 0;

    cvNamedWindow("Play video", WINDOW_AUTOSIZE );

    g_capture = cvCreateFileCapture(video_path);

    int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
    one_per = frames/1000;
    if(0 == one_per){

        one_per = 1;
    }

    printf("one_per = %d\n", one_per);
    if(0 != frames){

        cvCreateTrackbar("Position","Play video",&g_slider_position,frames,onTrackbarSlide);
    }

    IplImage *frame;

    while(1){

        frame = cvQueryFrame(g_capture);
        if(!frame){

            printf("frame is NULL!\n");
            break;
        }

        cvShowImage("Play video", frame);

        cur_pos++;
        printf("cur_pos = %d, one_per = %d, (cur_pos mod one_per)  = %d \n", cur_pos,one_per,cur_pos %one_per);
        if((0 == (cur_pos % one_per) ) && (cur_pos > one_per)){
            printf("setTrackbarPos\n");
            setTrackbarPos("Position", "Play video", cur_pos);
        }

        char c = cvWaitKey(10);
        if(27 == c){

            printf("cvCapture c = 27\n");
            break;
        }

    }



}

int VideoPlayer::CameraPlay()
{
    camera_capture = cvCreateCameraCapture(0);

    assert(camera_capture != NULL);

    IplImage *frame;

    while(1){

        frame = cvQueryFrame(g_capture);
        if(!frame){

            printf("frame is NULL!\n");
            continue;;
        }

        cvShowImage("RC *", frame);


        char c = cvWaitKey(10);
        if(27 == c){

            printf("cvCapture c = 27\n");
            break;
        }

    }
}

int VideoPlayer::ScaleVideo(char *video_src_path,  char *video_dst_path)
{
    int one_per = 0;

    //cvNamedWindow("src video", WINDOW_AUTOSIZE );

    CvCapture *capture = cvCreateFileCapture(video_src_path);
    if(NULL == capture ){

        printf("capture  = NULL\n");
    }

    double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);

    CvSize size = cvSize(cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
                     cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
    IplImage *frame;
    frame = cvQueryFrame(capture);
    if(NULL == frame ){

        printf("frame  = NULL\n");
    }

    //CvVideoWriter *write = cvCreateVideoWriter(video_dst_path,  CV_FOURCC_MACRO('H', '2', '6', '4'),fps,size);
    //CvVideoWriter *write = cvCreateVideoWriter(video_dst_path,  CV_FOURCC_MACRO('X', '2', '6', '4'),fps,size);
    CvVideoWriter *write = cvCreateVideoWriter(video_dst_path,  CV_FOURCC('M', 'J', 'P', 'G'),fps,size);
    if(NULL == write){

        printf("write = NULL\n");
    }

    IplImage *image_out = cvCreateImage(size, IPL_DEPTH_8U,  3);
    if(NULL == image_out){

        printf("image_out = NULL\n");
    }

    while((frame = cvQueryFrame(capture)) != NULL){

        //cvLogPolar(frame ,  image_out,
        //		  cvPoint2D32f(frame->width, frame->height), 60,
        //		  CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
        cvWriteFrame(write, frame);

    }

    cvReleaseVideoWriter(&write);
    cvReleaseImage(&image_out);
    cvReleaseCapture(&capture);

    printf("ScaleVideo OK\n");
    return 0;

}

