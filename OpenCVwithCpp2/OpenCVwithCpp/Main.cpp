/*
 * Subject: OpenCV Project - Main Menu
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: Main.cpp
 * Description:
 *
*/

#include <iostream>
#include "main.h"

using namespace std;

Main::Main() {
	controller = NULL;
}

Main::~Main() {
	delete[] controller;
}

void Main::run() {

	controller = new MainController();
	char myCh;
	bool status = false;

	int i;
	const int START_MENU = 0;
	const int END_MENU = 4;

	while (1) {

		i = START_MENU;
		while (i <= END_MENU) {
			display(i);
			i++;
		}

		cin >> myCh;

		switch (myCh) {

			case '1':
				controller->showWebCamera();
				break;

			case '2':
				controller->saveWebCamera();
				break;
			
			case '3':
				controller->loadWebVideo();
				break;

			case '4':
				controller->objectDetection();
				break;

			case 'q':
				status = true;
				break;

		}

		if (status == true)
			break;
		else {
			cout << "------------------------------------" << endl;
			cout << "------------------------------------" << endl;
			cout << endl;
		}

	}
	
}

void Main::display(int n) {

	if (n == 0) {
		cout << "|--------------------------------------------------|" << endl;
		cout << "|                                          |       |" << endl;
		cout << "|   Ű���带 �Է����ּ���.                 |       |" << endl;
		cout << "|--------------------------------------------------|" << endl;
	}
	else {
		cout << n << "��:";
	}

	switch (n)
	{
		case 1:
			cout << "��ī�޶� - ����" << endl;
			break;

		case 2:
			cout << "��ī�޶� - ĸ�� ���� ����" << endl;
			break;

		case 3:
			cout << "��ī�޶� - ���� �ҷ�����" << endl;
			break;

		case 4:
			cout << "��ü Ž���ϱ�" << endl;
			break;

		default:
			break;

	} // end of switch

}