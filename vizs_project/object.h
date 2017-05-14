#ifndef OBJECT_H
#define OBJECT_H

#include <sstream>
#include <string>
#include <iostream>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

class Object
{
public:
    Object();
    //capture frame width and height
    const int WIDTH = 640;
    const int HEIGHT = 480;
    //max number of objects to be tracked in frame
    static const int MAX_OBJECTS = 20;

    void morphObject(cv::Mat &thresh);
    void trackObject(cv::Mat threshold, cv::Mat &cameraFeed, int shapeID);
};

#endif // OBJECT_H
