#include "InOutInfo.h"

void InOutInfo::manage() {
	system("cls");
	outColor.print("*******������Ϣ����*******", outColor.GREEN);
	int opCode(0);
	while (1) {
		cout << "�㺦��¹�? 1.¼�� 2.ɾ�� 3.��� 4.��ӡ������Ϣ 5.�˻���һ��" << endl;
		cout << "��������Ҫ�Ĳ���: ";
		cin >> opCode;
		switch (opCode) {
		case INPUT:
			if (input())
				outColor.print("*******¼����ɣ�*******", outColor.GREEN);
			break;
		case REMOVE: {
			if (remove())
				outColor.print("*******ɾ����ɣ�*******", outColor.GREEN);
			else
				outColor.print("*******ɾ��ʧ�ܣ�*******", outColor.RED);
			break;
		}
		case CLEAR: {
			int errorCode = 0;
			if (clear(errorCode))
				outColor.print("*******������Ϣ�Ѿ���գ�*******", outColor.GREEN);
			else {
				switch (errorCode)
				{
				case 1:
					outColor.print("*******���ʧ�ܣ�ԭ����ȡ���˲�����*******", outColor.RED);
					break;
				case 2:
					outColor.print("*******���ʧ�ܣ�ԭ�򣺽�����Ϣ�б�գ�*******", outColor.RED);
					break;
				default:
					break;
				}
			}
			break;
		}
		case PRINT: {
			if (print())
				outColor.print("*******��ӡ��ɣ�*******", outColor.GREEN);
			else
				outColor.print("*******��ӡʧ�ܣ��޽�����Ϣ��*******", outColor.RED);
			break;
		}
		case BACK:
			return;
		default:
			outColor.print("��ɶ�أ�С�ϵܶ���û�����ֲ�����", outColor.RED);
		}
	}
}

bool InOutInfo::input() {
	cout << "��ʼ��������Ա��Ϣ(�����ʽ������,ְҵ,������,����,ʱ��,����; �Ե��о��Ž���)��" << endl;
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
		cout << "��Ч����Ϣ���£�" << endl;
		cout << "���\t����\t���\t������\t����\t����ʱ��\t��/��\n";
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
	cout << "��¼����Ҫɾ���Ľ�����Ϣ����ţ�" << endl;
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
		cout << "�Ƿ�ȷ��Ҫɾ��ȫ����Ч����Ϣ��1.�� 2.��" << endl;
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
	if (g == "��")
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