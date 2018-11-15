#include "GateManager.h"

void GateManager::manage() {
	int opCode(0);
	while (1) {
		system("cls");
		outColor.print("欢迎来到161220131王志邦的门禁管理系统", outColor.GREEN);
		cout << "你想嘎哈? 1.卡权限管理 2.人脸权限管理 3.进出信息管理 4.模拟结果 5.退出程序" << endl;
		cout << "输入你想要的操作:";
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
			outColor.print("没这种操作,你想啥呢!小老弟儿!", outColor.RED);
			Sleep(800);
		}
	}
}