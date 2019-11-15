/*
 * Subject: OpenCV Project - 기능 명세
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: MainController.h
 * Description:
 *
*/

#pragma once
#ifndef _MainController_H_
#define _MainController_H_

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class MainController {

private:
	Mat frame;
	VideoCapture* camera;

public:
	MainController();
	~MainController();

	int showWebCamera();
	int saveWebCamera();
	int loadWebVideo();
	int objectDetection();

protected:

};

#endif