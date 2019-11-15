/*
 * Subject: OpenCV Project
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: Main.cpp
 * Description:
 *
*/

#include <Windows.h>
#include <string.>
#include <thread>
#include <iostream>
#include "main.h"

using namespace std;

void myThread();
void greeting();

int main() {
	
	using namespace std;
	thread t1(myThread);

	t1.join();		// 기다렸다가 종료

	return 0;

}

void myThread() {
	greeting();
	Main* mainApp = new Main();
	mainApp->run();
}

void greeting() {

	cout << "/////////////////////////////////////////////////////////" << endl;
	cout << "//        Welcome to OpenCV with CPP, Socket" << endl;
	cout << "//                                                     //" << endl;
	cout << "//                                                     //" << endl;
	cout << "/////////////////////////////////////////////////////////" << endl;

}