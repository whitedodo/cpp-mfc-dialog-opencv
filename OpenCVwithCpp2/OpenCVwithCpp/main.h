/*
 * Subject: OpenCV Project - 프로그램
 * Created date: 2019-11-15
 * Author: Dodo (rabbit.white@daum.net)
 * FileName: Main.h
 * Description:
 *
*/

#pragma once

#ifndef _MAIN_H_
#define _MAIN_H_

#include "MainController.h"

class Main {

private:
	MainController* controller;
public:
	Main();
	~Main();
	void run();
	void display(int n);

protected:


};

#endif