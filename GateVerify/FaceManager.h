#pragma once

#include <iostream>
#include "OutputColorConfig.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FaceManager
{
private:
	enum opNameEnum { ZERO, INPUT, REMOVE, CLEAR, PRINT, BACK };
	vector<int> faceIdList;
	OutputColorConfig outColor;
	bool input();
	bool remove();
	bool print();
	bool clear(int &errorCode);
public:
	void manage();
	bool OK(int);
};

