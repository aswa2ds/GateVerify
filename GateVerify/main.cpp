#include <iostream>
using namespace std;
#include "GateManager.h"

int main() {
	GateManager gateManager;
	gateManager.manage();
	return 0;
}

/*
	����������
	A,ѧ��,,2,8:00,��;
	B,ѧ��,,3,8:05,��;
	C,��ʦ,1,5,8:05,��;
	D,��ʦ,2,6,8:10,��;
	E,ѧ��,,4,8:10,��;
	#
	1,2,5;
	2,3,4;
	4,7;
	2;
	F,ѧ��,,4,9:00,��;
	G,ѧ��,,6,9:00,��;
	H,��ʦ,2,7,9:05,��;
	#
*/