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
	string teacher = "老师";
	string studeng = "学生";
public:
	void doSimulate(InOutInfo, FaceManager, CardManager);
};

