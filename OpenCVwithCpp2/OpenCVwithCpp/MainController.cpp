/*
 * Subject: OpenCV Project - ��� ��
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
		cerr << "���� - ī�޶� �� �� �����ϴ�.\n";
		cerr << "Error - Camera is not opened\n";
		return -1;
	}

	while (1) {

		// ī�޶���� ĸó�� ������ frame�� �ӽ� ����
		camera->read(frame);
		if (frame.empty()) {
			cerr << "�� ������ ĸ�ĵǾ����ϴ�.\n";
			break;
		}

		// ������ ȭ�鿡 ������.
		imshow("Color", frame);

		// ESCŰ�� �Է��ϸ� ���� ����
		if (waitKey(25) >= 0)
			break;

	}

	camera->release();		// �� ī�޶� ����
	destroyAllWindows();	// â ����
	
	return 0;

}

int MainController::saveWebCamera() {

	frame;
	camera = new VideoCapture(0);	// 0�� ��ī�޶�, 1�� �ܺ�ī�޶�

	// ���� ĸ�� �ʱ�ȭ
	if (!camera->isOpened()) {
		cerr << "���� - ī�޶� �� �� �����ϴ�.\n";
		cerr << "Error - Camera is not opened.\n";
		return -1;
	}

	// ������ ������ �����ϱ� ���� �غ�
	Size size = Size((int)camera->get(CAP_PROP_FRAME_WIDTH),
					 (int)camera->get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;
	double fps = 30.0;
	writer.open("D:/output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps,	size, true);

	if (!writer.isOpened()) {
		cout << "�������� �����ϱ� ���� �ʱ�ȭ �۾� �� ���� �߻�" << endl;
		return 1;
	}

	while (1)
	{
		camera->read(frame);
		if (frame.empty()) {
			cerr << "�� ������ ĸ�ĵǾ����ϴ�.\n";
			break;
		}

		//������ ���Ͽ� �� �������� ������.  
		writer.write(frame);

		imshow("Color", frame);

		if (waitKey(25) >= 0)
			break;

	}

	camera->release();		// �� ī�޶� ����
	destroyAllWindows();	// â ����
	return 0;

}

int MainController::loadWebVideo() {

	camera = new VideoCapture("D:/output.avi");

	if (!camera->isOpened()) {
		cerr << "���� - ī�޶� �� �� �����ϴ�.\n";
		cerr << "Error - Camera is not opened.\n";

		return -1;
	}

	while (1) {

		camera->read(frame);
		if (frame.empty()) {
			cerr << "�� �����Դϴ�.\n" << endl;
			break;
		}

		imshow("����(Movie)", frame);

		if (waitKey(25) >= 0)
			break;

	}

	camera->release();		// �� ī�޶� ����
	destroyAllWindows();	// â ����
	return 0;

}


int MainController::objectDetection() {

	ObjectDetection* objDetection = new ObjectDetection();
	objDetection->detection();

	return 0;
}