#include "FaceManager.h"

void FaceManager::manage() {
	system("cls");
	outColor.print("*******人脸信息管理*******", outColor.GREEN);
	int opCode(0);
	while (1) {
		cout << "你害想嘎哈? 1.录入 2.删除 3.清空 4.打印有效人脸id 5.退回上一步" << endl;
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
				outColor.print("*******有效人脸信息已经清空！*******", outColor.GREEN);
			else {
				switch (errorCode)
				{
				case 1:
					outColor.print("*******清空失败！原因：您取消了操作！*******", outColor.RED);
					break;
				case 2:
					outColor.print("*******清空失败！原因：有效卡列表空！*******", outColor.RED);
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
				outColor.print("*******打印失败，无有效人脸信息！*******", outColor.RED);
			break;
		}
		case BACK:
			return;
		default:
			outColor.print("想啥呢！小老弟儿！没有这种操作！", outColor.RED);
		}
	}
}

bool FaceManager::input() {
	cout << "请录入有效人脸id：" << endl;
	string line;
	getline(cin, line, ';');
	istringstream input;
	input.str(line);
	for (string num; getline(input, num, ',');) {
		faceIdList.push_back(atoi(&num[0]));
	}
	return true;
}

bool FaceManager::remove() {
	cout << "请录入无效人脸信息：" << endl;
	string line;
	getline(cin, line, ';');
	istringstream input;
	input.str(line);
	for (string num; getline(input, num, ',');) {
		for (int i = 0; i < faceIdList.size(); ++i) {
			if (faceIdList[i] == atoi(&num[0])) {
				vector<int>::iterator it = faceIdList.begin();
				faceIdList.erase(it + i);
			}
		}
	}
	return true;
}

bool FaceManager::print() {
	if (!faceIdList.empty()) {
		cout << "有效人脸信息如下：" << endl;
		for (vector<int>::iterator it = faceIdList.begin(); it != faceIdList.end(); ++it)
			cout << *it << " ";
		cout << endl;
		return true;
	}
	else return false;
}

bool FaceManager::clear(int &errorCode) {
	if (!faceIdList.empty()) {
		cout << "是否确定要删除全部有效人脸信息？1.是 2.否" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			faceIdList.clear();
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

bool FaceManager::OK (int faceId) {
	for (vector<int>::iterator it = faceIdList.begin(); it != faceIdList.end(); ++it) {
		if (*it == faceId)
			return true;
	}
	return false;
}