#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

class OutputColorConfig
{
public:
	enum ColorEnum {GREEN, RED, WHITE};
private:
	void setForeGround(ColorEnum color);
public:
	void print(const char* str, ColorEnum color);
};

