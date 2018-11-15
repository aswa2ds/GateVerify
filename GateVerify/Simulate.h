#pragma once

#include <iostream>
#include <string>
#include "CardManager.h"
#include "FaceManager.h"
#include "InOutInfo.h"
#include "OutputColorConfig.h"

using namespace std;

class Simulate
{
private:
	OutputColorConfig outColor;
	string teacher = "��ʦ";
	string studeng = "ѧ��";
public:
	void doSimulate(InOutInfo, FaceManager, CardManager);
};

