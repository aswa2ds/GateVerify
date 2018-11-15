#include "Simulate.h"

void Simulate::doSimulate(InOutInfo inOutInfo, FaceManager faceManager, CardManager cardManager) {
	vector<InOutData> infoList = inOutInfo.getList();
	for (vector<InOutData>::iterator it = infoList.begin(); it != infoList.end(); ++it) {
		InOutData person = *it;
		if (person.IO) {
			switch (person.work == this->teacher)
			{
			case true: {
				if (faceManager.OK(person.faceId)) 
					cout << person.work << " " << person.name << ": " << "有效人脸识别 " << person.timetoa() << " " << "进系楼" << endl;
				else if(cardManager.OK(person.cardId))
					cout << person.work << " " << person.name << ": " << "无效人脸识别，有效刷卡 " << person.timetoa() << " " << "进系楼" << endl;
				else
					cout << person.work << " " << person.name << ": " << "无效人脸识别，无效刷卡 " << person.timetoa() << " " << "未进系楼" << endl;
				break;
			}
			case false: {
				if (cardManager.OK(person.cardId))
					cout << person.work << " " << person.name << ": " << "有效刷卡 " << person.timetoa() << " " << "进系楼" << endl;
				else
					cout << person.work << " " << person.name << ": " << "无效刷卡 " << person.timetoa() << " " << "未进系楼" << endl;
				break;
			}
			}
		}
		else 
			cout << person.work << " " << person.name << ": " << person.timetoa() << " " << "出系楼" << endl;
	}
	cout << endl;
	cout << "输入任意字符返回:";
	char ch;
	cin >> ch;
}