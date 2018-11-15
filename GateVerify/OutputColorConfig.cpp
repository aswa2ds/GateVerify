#include "OutputColorConfig.h"

void OutputColorConfig::setForeGround(ColorEnum color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color)
	{
	case OutputColorConfig::GREEN: {
		SetConsoleTextAttribute(handle, 10);
		break;
	}
	case OutputColorConfig::RED:
		SetConsoleTextAttribute(handle, 12);
		break;
	case OutputColorConfig::WHITE:
		SetConsoleTextAttribute(handle, 15);
		break;
	default:
		break;
	}
}

void OutputColorConfig::print(const char* str, ColorEnum color) {
	setForeGround(color);
	cout << str << endl;
	setForeGround(WHITE);
}
