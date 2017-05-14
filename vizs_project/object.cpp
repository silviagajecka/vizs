#include "object.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;

Object::Object()
{

}

/**
* Helper function to find a cosine of angle between vectors
* from pt0->pt1 and pt0->pt2
*/
static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

/**
* Helper function to display text in the center of a contour
*/
void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour)
{
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.4;
    int thickness = 1;
    int baseline = 0;

    cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
    cv::Rect r = cv::boundingRect(contour);

    cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
    cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255, 255, 255), CV_FILLED);
    cv::putText(im, label, pt, fontface, scale, CV_RGB(0, 0, 0), thickness, 8);
}


void Object::morphObject(Mat &thresh){

    //create structuring element that will be used to "dilate" and "erode" image.
    //the element chosen here is a 3px by 3px rectangle
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
    //dilate with larger element so make sure object is nicely visible
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));

    erode(thresh, thresh, erodeElement);
    erode(thresh, thresh, erodeElement);
    dilate(thresh, thresh, dilateElement);
    dilate(thresh, thresh, dilateElement);
}

void Object::trackObject(Mat threshold, Mat &cameraFeed, int shapeID) {

    Mat temp,srcBlur,srcCanny;
    threshold.copyTo(temp);
    //these two vectors needed for output of findContours
    vector< vector<Point> > contours;
    vector<Point> approx;
    vector<Vec4i> hierarchy;
    vector<Point> ConvexHullPoints;

    blur(threshold, srcBlur, Size(3, 3));
    Canny(srcBlur, srcCanny, 0, 100, 3, true);

    //find contours of filtered image using openCV findContours function
    findContours(srcCanny, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);


    //use moments method to find our filtered object
    if (hierarchy.size() > 0) {
        int numObjects = hierarchy.size();
        //if number of objects greater than MAX_OBJECTS we have a noisy filter
        if (numObjects<MAX_OBJECTS) {
            for (unsigned int i = 0; i < contours.size(); i++) {

                convexHull(Mat(contours[i]), ConvexHullPoints);

                // zistuje pocet vrcholov na objekte
                cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

                // Skip small or non-convex objects
                if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
                    continue;

                if (approx.size() == 3 && shapeID == 1) {
                    polylines( cameraFeed, approx, true, Scalar(0,0,255), 3 );
                    setLabel(cameraFeed, "TRI", contours[i]);    // Triangles
                }
                else if (approx.size() >= 4 && approx.size() <= 6) {
                    // Number of vertices of polygonal curve
                    int vtc = approx.size();

                    // Get the cosines of all corners
                    std::vector<double> cos;
                    for (int j = 2; j < vtc + 1; j++)
                        cos.push_back(angle(approx[j%vtc], approx[j - 2], approx[j - 1]));

                    // Sort ascending the cosine values
                    std::sort(cos.begin(), cos.end());

                    // Get the lowest and the highest cosine
                    double mincos = cos.front();
                    double maxcos = cos.back();

                    // Use the degrees obtained above and the number of vertices
                    // to determine the shape of the contour
                    if (vtc == 4 && mincos >= -0.1 && maxcos <= 0.3 && shapeID == 2) {
                        polylines( cameraFeed, approx, true, Scalar(0,0,255), 3 );
                        setLabel(cameraFeed, "RECT", contours[i]);
                    }
                    else if (vtc == 5 && mincos >= -0.35 && maxcos <= -0.21 && shapeID == 3) {
                        polylines( cameraFeed, approx, true, Scalar(0,0,255), 3 );
                        setLabel(cameraFeed, "PENTA", contours[i]);
                    }
                    else if (vtc == 6 && mincos >= -0.55 && maxcos <= -0.45 && shapeID == 4) {
                        polylines( cameraFeed, approx, true, Scalar(0,0,255), 3 );
                        setLabel(cameraFeed, "HEXA", contours[i]);
                    }
                }
                else {
                    // Detect and label circles
                    double area = cv::contourArea(contours[i]);
                    cv::Rect r = cv::boundingRect(contours[i]);
                    int radius = r.width / 2;

                    if (std::abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                        std::abs(1 - (area / (CV_PI * (radius*radius)))) <= 0.2 && shapeID == 0) {
                        polylines( cameraFeed, ConvexHullPoints, true, Scalar(0,0,255), 3 );
                        setLabel(cameraFeed, "CIR", contours[i]);
                    }
                }
            }
        }
    }
}
