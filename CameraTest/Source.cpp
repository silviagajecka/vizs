#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int counter = 0;

int nahraj(VideoCapture cap, int camNum) {

	cap.open(camNum);
	
	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;
	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

	/*VideoWriter oVideoWriter("C:/Users/Lenka/Documents/Visual Studio 2015/Projects/CameraTest/video/MyVideo.avi", CV_FOURCC('M', 'P', '4', '2'), 24, frameSize, true); //initialize the VideoWriter object

	if (!oVideoWriter.isOpened()) //if not initialize the VideoWriter successfully, exit the program
	{
	cout << "ERROR: Failed to write the video" << endl;
	return -1;
	}
	*/

	while (1)
	{
		Mat frame;
		stringstream file;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		//oVideoWriter.write(frame); //writer the frame into the file

		if(counter < 10)
			file << "G:/School/Ing/1. roèník/Letný semester/VIZS/imgCam/image0" << counter << ".jpg";
		else
			file << "G:/School/Ing/1. roèník/Letný semester/VIZS/imgCam/image" << counter << ".jpg";
		
		counter++;
		imwrite(file.str(), frame);

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
	
}

int prehraj() {

	//string cesta = "C:/Users/Silvia/Desktop/imgCam";
	VideoCapture cap("G:/School/Ing/1. roèník/Letný semester/VIZS/imgCam/image%02d.jpg");
	
	/*cin.ignore();
	cout << "Zadaj cestu:" << endl;*/
	
    /*cesta.append("/image%02d.jpg");
	cap.open(cesta);*/

	
	


	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		cin.get();
	}

	//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms
	//double fps = cap.set(CV_CAP_PROP_FPS, 0);

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	cout << "Frame per seconds : " << fps << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(80) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;
}



int main(int argc, char* argv[])
{

	VideoCapture cap; // open the video camera no. 0
	

	int volba;
	cout << "Co by si rad?" << endl;
	cout << "1. Nahrat video." << endl;
	cout << "2. Spustit video." << endl;


	cin >> volba;
	if (volba == 1)

		nahraj(cap, 0);

	else
		prehraj();

	return 0;
}



