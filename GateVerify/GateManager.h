#pragma once
#include <iostream>
#include "OutputColorConfig.h"
#include "CardManager.h"
#include "FaceManager.h"
#include "InOutInfo.h"
#include "Simulate.h"

using namespace std;

class GateManager {
private:
	OutputColorConfig outColor;
	CardManager cardManager;
	FaceManager faceManager;
	InOutInfo inOutInfo;
	Simulate simulate;
	enum opNameEnum { ZERO, CARDMANAGE, FACEMANAGE, INFOMANAGE, RESULT, EXIT };
public:
	void manage();
};
