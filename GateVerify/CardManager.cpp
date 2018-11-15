#include "CardManager.h"

void CardManager::manage() {
	system("cls");
	outColor.print("*******����Ϣ����*******", outColor.GREEN);
	int opCode(0);
	while (1) {
		cout << "�㺦��¹�? 1.¼�� 2.ɾ�� 3.��� 4.��ӡ��Чˢ��id 5.�˻���һ��" << endl;
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
				outColor.print("*******��Ч����Ϣ�Ѿ���գ�*******", outColor.GREEN);
			else {
				switch (errorCode)
				{
				case 1:
					outColor.print("*******���ʧ�ܣ�ԭ����ȡ���˲�����*******", outColor.RED);
					break;
				case 2:
					outColor.print("*******���ʧ�ܣ�ԭ����Ч���б�գ�*******", outColor.RED);
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
				outColor.print("*******��ӡʧ�ܣ�����Ч����Ϣ��*******", outColor.RED);
			break;
		}
		case BACK:
			return;
		default:
			outColor.print("��ɶ�أ�С�ϵܶ���û�����ֲ�����", outColor.RED);
		}
	}
}

bool CardManager::input() {
	cout << "��¼����Ч��id��" << endl;
	string line;
	getline(cin, line, ';');
	istringstream input;
	input.str(line);
	for (string num; getline(input, num, ',');) {
		cardIdList.push_back(atoi(&num[0]));
	}
	return true;
}

bool CardManager::remove() {
	cout << "��¼����Ч��id��" << endl;
	string line;
	getline(cin, line, ';');
	istringstream input;
	input.str(line);
	for (string num; getline(input, num, ',');) {
		for (int i = 0; i < cardIdList.size(); ++i) {
			if (cardIdList[i] == atoi(&num[0])) {
				vector<int>::iterator it = cardIdList.begin();
				cardIdList.erase(it+i);
			}
		}
	}
	return true;
}

bool CardManager::print() {
	if (!cardIdList.empty()) {
		cout << "��Ч����Ϣ���£�" << endl;
		for (vector<int>::iterator it = cardIdList.begin(); it != cardIdList.end(); ++it)
			cout << *it << " ";
		cout << endl;
		return true;
	}
	else return false;
}

bool CardManager::clear(int &errorCode) {
	if (!cardIdList.empty()) {
		cout << "�Ƿ�ȷ��Ҫɾ��ȫ����Ч����Ϣ��1.�� 2.��" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cardIdList.clear();
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

bool CardManager::OK(int cardId) {
	for (vector<int>::iterator it = cardIdList.begin(); it != cardIdList.end(); ++it) {
		if (*it == cardId)
			return true;
	}
	return false;
}