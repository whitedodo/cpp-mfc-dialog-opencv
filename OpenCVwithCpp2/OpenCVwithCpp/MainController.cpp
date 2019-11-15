/*
 * Subject: OpenCV Project - 기능 명세
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: MainController.cpp
 * Description:
 *
*/

#include "MainController.h"
#include "ObjectDetection.h"

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

MainController::MainController() {
	camera = NULL;
}

MainController::~MainController() {
	if(!camera->isOpened())
		camera->release();
}

int MainController::showWebCamera() {

	camera = new VideoCapture(0);

	if (!camera->isOpened()) {
		cerr << "에러 - 카메라를 열 수 없습니다.\n";
		cerr << "Error - Camera is not opened\n";
		return -1;
	}

	while (1) {

		// 카메라부터 캡처한 영상을 frame에 임시 저장
		camera->read(frame);
		if (frame.empty()) {
			cerr << "빈 영상이 캡쳐되었습니다.\n";
			break;
		}

		// 영상을 화면에 보여줌.
		imshow("Color", frame);

		// ESC키를 입력하면 루프 종료
		if (waitKey(25) >= 0)
			break;

	}

	camera->release();		// 웹 카메라 끄기
	destroyAllWindows();	// 창 종료
	
	return 0;

}

int MainController::saveWebCamera() {

	frame;
	camera = new VideoCapture(0);	// 0은 웹카메라, 1은 외부카메라

	// 비디오 캡쳐 초기화
	if (!camera->isOpened()) {
		cerr << "에러 - 카메라를 열 수 없습니다.\n";
		cerr << "Error - Camera is not opened.\n";
		return -1;
	}

	// 동영상 파일을 저장하기 위한 준비
	Size size = Size((int)camera->get(CAP_PROP_FRAME_WIDTH),
					 (int)camera->get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;
	double fps = 30.0;
	writer.open("D:/output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps,	size, true);

	if (!writer.isOpened()) {
		cout << "동영상을 저장하기 위한 초기화 작업 중 에러 발생" << endl;
		return 1;
	}

	while (1)
	{
		camera->read(frame);
		if (frame.empty()) {
			cerr << "빈 영상이 캡쳐되었습니다.\n";
			break;
		}

		//동영상 파일에 한 프레임을 저장함.  
		writer.write(frame);

		imshow("Color", frame);

		if (waitKey(25) >= 0)
			break;

	}

	camera->release();		// 웹 카메라 끄기
	destroyAllWindows();	// 창 종료
	return 0;

}

int MainController::loadWebVideo() {

	camera = new VideoCapture("D:/output.avi");

	if (!camera->isOpened()) {
		cerr << "에러 - 카메라를 열 수 없습니다.\n";
		cerr << "Error - Camera is not opened.\n";

		return -1;
	}

	while (1) {

		camera->read(frame);
		if (frame.empty()) {
			cerr << "빈 영상입니다.\n" << endl;
			break;
		}

		imshow("영상(Movie)", frame);

		if (waitKey(25) >= 0)
			break;

	}

	camera->release();		// 웹 카메라 끄기
	destroyAllWindows();	// 창 종료
	return 0;

}


int MainController::objectDetection() {

	ObjectDetection* objDetection = new ObjectDetection();
	objDetection->detection();

	return 0;
}