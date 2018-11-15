#include "GateManager.h"

void GateManager::manage() {
	int opCode(0);
	while (1) {
		system("cls");
		outColor.print("��ӭ����161220131��־����Ž�����ϵͳ", outColor.GREEN);
		cout << "����¹�? 1.��Ȩ�޹��� 2.����Ȩ�޹��� 3.������Ϣ���� 4.ģ���� 5.�˳�����" << endl;
		cout << "��������Ҫ�Ĳ���:";
		cin >> opCode;
		switch (opCode) {
		case CARDMANAGE: {
			cardManager.manage();
			break;
		}
		case FACEMANAGE: {
			faceManager.manage();
			break;
		}
		case INFOMANAGE: {
			inOutInfo.manage();
			break;
		}
		case RESULT: {
			simulate.doSimulate(inOutInfo, faceManager, cardManager);
			break;
		}
		case EXIT: {
			return;
		}
		default:
			outColor.print("û���ֲ���,����ɶ��!С�ϵܶ�!", outColor.RED);
			Sleep(800);
		}
	}
}