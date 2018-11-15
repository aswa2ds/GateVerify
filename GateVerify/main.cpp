#include <iostream>
using namespace std;
#include "GateManager.h"

int main() {
	GateManager gateManager;
	gateManager.manage();
	return 0;
}

/*
	测试用例：
	A,学生,,2,8:00,进;
	B,学生,,3,8:05,出;
	C,老师,1,5,8:05,出;
	D,老师,2,6,8:10,进;
	E,学生,,4,8:10,进;
	#
	1,2,5;
	2,3,4;
	4,7;
	2;
	F,学生,,4,9:00,进;
	G,学生,,6,9:00,出;
	H,老师,2,7,9:05,进;
	#
*/