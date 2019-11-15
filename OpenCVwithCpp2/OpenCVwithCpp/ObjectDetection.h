/*
 * Subject: OpenCV Project - ��ü Ž��
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: ObjectDetection.h
 * Description:
 * 19.11.15 / Dodo / ��ü Ž�� �ӵ� ����.
*/

#pragma once
#ifndef _OBJECT_DETECTION_H_
#define _OBJECT_DETECTION_H_

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

class ObjectDetection {

private:

	/** Global variables */
	CascadeClassifier* face_cascade;
	CascadeClassifier* eyes_cascade;

public:
	ObjectDetection();
	~ObjectDetection();

	/** Function Headers */
	void detectAndDisplay(Mat frame);
	int detection();

protected:



};

#endif