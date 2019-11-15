/*
 * Subject: OpenCV Project - 물체 탐지
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: ObjectDetection.cpp
 * Description:
 *
*/

#include "ObjectDetection.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

ObjectDetection::ObjectDetection() {
	face_cascade = NULL;
	eyes_cascade = NULL;
}

ObjectDetection::~ObjectDetection() {
	delete[] face_cascade;
	delete[] eyes_cascade;
}

void ObjectDetection::detectAndDisplay(Mat frame) {

	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	std::vector<Rect> faces;
	face_cascade->detectMultiScale(frame_gray, faces);

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);

		Mat faceROI = frame_gray(faces[i]);

		//-- In each face, detect eyes
		std::vector<Rect> eyes;
		eyes_cascade->detectMultiScale(faceROI, eyes);

		for (size_t j = 0; j < eyes.size(); j++)
		{
			Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
			int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
			circle(frame, eye_center, radius, Scalar(255, 0, 0), 4);
		}
	}

	//-- Show what you got
	imshow("Capture - Face detection", frame);

}

int ObjectDetection::detection() {

	String face_cascade_name = "haarcascade_frontalface_alt.xml";
	String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

	face_cascade = new CascadeClassifier(face_cascade_name);
	eyes_cascade = new CascadeClassifier(eyes_cascade_name);

	//-- 1. Load the cascades
	if (!face_cascade->load(face_cascade_name))
	{
		cout << "--(!)Error loading face cascade\n";
		return -1;
	};

	if (!eyes_cascade->load(eyes_cascade_name))
	{
		cout << "--(!)Error loading eyes cascade\n";
		return -1;
	};

	int camera_device = 0;
	VideoCapture capture;

	//-- 2. Read the video stream
	capture.open(camera_device);
	if (!capture.isOpened())
	{
		cout << "--(!)Error opening video capture\n";
		return -1;
	}

	capture.set(cv::CAP_PROP_FPS, 120);

	Mat frame;
	while (capture.read(frame))
	{
		if (frame.empty())
		{
			cout << "--(!) No captured frame -- Break!\n";
			break;
		}

		//-- 3. Apply the classifier to the frame
		detectAndDisplay(frame);

		if (waitKey(25) == 27)
		{
			break; // escape
		}
	}

	capture.release();
	destroyAllWindows();	// 창 종료

	return 0;

}