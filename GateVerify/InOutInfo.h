#pragma once

#include "OutputColorConfig.h"
#include "string"
#include <sstream>
#include <vector>

constexpr auto PERSONIN = true;
constexpr auto PERSONOUT = false;

struct InOutData {
private:
	int atotime(string timeStr);
public:
	string name;
	string work;
	int faceId;
	int cardId;
	int time;
	bool IO;
	InOutData(string a, string b, string c, string d, string f, string g);
	string timetoa();
	void print();
};

class InOutInfo{
private:
	enum opNameEnum { ZERO, INPUT, REMOVE, CLEAR, PRINT, BACK };
	vector<InOutData> inOutDataList;
	OutputColorConfig outColor;
	bool input();
	bool remove();
	bool print();
	bool clear(int &errorCode);
public:
	void manage();
	vector<InOutData> getList();
};

