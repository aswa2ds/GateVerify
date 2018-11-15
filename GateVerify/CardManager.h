#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
#include "OutputColorConfig.h"
using namespace std;

class CardManager {
private:
	enum opNameEnum { ZERO, INPUT, REMOVE, CLEAR, PRINT, BACK };
	vector<int> cardIdList;
	OutputColorConfig outColor;
	bool input();
	bool remove();
	bool print();
	bool clear(int &errorCode);
public:
	void manage();
	bool OK(int);
};