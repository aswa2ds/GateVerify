#include "InOutInfo.h"

void InOutInfo::manage() {
	system("cls");
	outColor.print("*******进出信息管理*******", outColor.GREEN);
	int opCode(0);
	while (1) {
		cout << "你害想嘎哈? 1.录入 2.删除 3.清空 4.打印进出信息 5.退回上一步" << endl;
		cout << "输入你想要的操作: ";
		cin >> opCode;
		switch (opCode) {
		case INPUT:
			if (input())
				outColor.print("*******录入完成！*******", outColor.GREEN);
			break;
		case REMOVE: {
			if (remove())
				outColor.print("*******删除完成！*******", outColor.GREEN);
			else
				outColor.print("*******删除失败！*******", outColor.RED);
			break;
		}
		case CLEAR: {
			int errorCode = 0;
			if (clear(errorCode))
				outColor.print("*******进出信息已经清空！*******", outColor.GREEN);
			else {
				switch (errorCode)
				{
				case 1:
					outColor.print("*******清空失败！原因：您取消了操作！*******", outColor.RED);
					break;
				case 2:
					outColor.print("*******清空失败！原因：进出信息列表空！*******", outColor.RED);
					break;
				default:
					break;
				}
			}
			break;
		}
		case PRINT: {
			if (print())
				outColor.print("*******打印完成！*******", outColor.GREEN);
			else
				outColor.print("*******打印失败，无进出信息！*******", outColor.RED);
			break;
		}
		case BACK:
			return;
		default:
			outColor.print("想啥呢！小老弟儿！没有这种操作！", outColor.RED);
		}
	}
}

bool InOutInfo::input() {
	cout << "初始化进出人员信息(输入格式：名字,职业,人脸号,卡号,时间,进出; 以单行井号结束)：" << endl;
	string line;
	while (cin >> line) {
		if (line == "#")
			break;
		line.pop_back();
		istringstream input;
		input.str(line);
		string *dataList = new string[6];
		int i = 0;
		while(getline(input, dataList[i++],','));
		InOutData inOutData(dataList[0], dataList[1], dataList[2], dataList[3], dataList[4], dataList[5]);
		//inOutData.print();
		if (inOutDataList.empty()) {
			inOutDataList.push_back(inOutData);
		}
		else {
			bool flag = false;
			for (vector<InOutData>::iterator it = inOutDataList.begin(); it != inOutDataList.end(); ++it) {
				if ((*it).time >= inOutData.time) {
					inOutDataList.insert(it, inOutData);
					flag = true;
					break;
				}
			}
			if (!flag)
				inOutDataList.push_back(inOutData);
		}
	}
	return true;
}

bool InOutInfo::print() {
	if (!inOutDataList.empty()) {
		cout << "有效卡信息如下：" << endl;
		cout << "序号\t姓名\t身份\t人脸号\t卡号\t进出时间\t进/出\n";
		int i = 1;
		for (vector<InOutData>::iterator it = inOutDataList.begin(); it != inOutDataList.end(); ++it) {
			cout << i++ << "\t";
			(*it).print();
		}
		return true;
	}
	else return false;
}
bool InOutInfo::remove() {
	print();
	cout << "请录入想要删除的进出信息的序号：" << endl;
	string line;
	getline(cin, line, ';');
	istringstream input;
	input.str(line);
	int i = 1;
	for (string num; getline(input, num, ',');) {
		vector<InOutData>::iterator it = inOutDataList.begin();
		inOutDataList.erase(it + (atoi(&num[0]) - i++));
	}
	print();
	return true;
}

bool InOutInfo::clear(int &errorCode) {
	if (!inOutDataList.empty()) {
		cout << "是否确定要删除全部有效卡信息？1.是 2.否" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			inOutDataList.clear();
			return true;
		}
		else {
			errorCode = 1;
			return false;
		}
	}
	else {
		errorCode = 2;
		return false;
	}
}

InOutData::InOutData(string a, string b, string c, string d, string f, string g) {
	name = a;
	work = b;
	if (c != "")
		faceId = atoi(&c[0]);
	else
		faceId = -1;
	cardId = atoi(&d[0]);
	time = atotime(f);
	if (g == "进")
		IO = PERSONIN;
	else
		IO = PERSONOUT;
}

int InOutData::atotime(string timeStr) {
	istringstream input;
	input.str(timeStr);
	string hour;
	string minute;
	getline(input, hour, ':');
	getline(input, minute);
	int time = atoi(&minute[0]) + 100 * atoi(&hour[0]);
	return time;
}

void InOutData::print() {
	cout << name << "\t" << work << "\t" << faceId << "\t" << cardId << "\t" << time << "\t\t" << IO << endl;
}

vector<InOutData> InOutInfo::getList() {
	return inOutDataList;
}

string InOutData::timetoa() {
	string timeStr = to_string(time);
	timeStr.insert(timeStr.length() - 2, ":");
	return timeStr;
}