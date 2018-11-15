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
					cout << person.work << " " << person.name << ": " << "��Ч����ʶ�� " << person.timetoa() << " " << "��ϵ¥" << endl;
				else if(cardManager.OK(person.cardId))
					cout << person.work << " " << person.name << ": " << "��Ч����ʶ����Чˢ�� " << person.timetoa() << " " << "��ϵ¥" << endl;
				else
					cout << person.work << " " << person.name << ": " << "��Ч����ʶ����Чˢ�� " << person.timetoa() << " " << "δ��ϵ¥" << endl;
				break;
			}
			case false: {
				if (cardManager.OK(person.cardId))
					cout << person.work << " " << person.name << ": " << "��Чˢ�� " << person.timetoa() << " " << "��ϵ¥" << endl;
				else
					cout << person.work << " " << person.name << ": " << "��Чˢ�� " << person.timetoa() << " " << "δ��ϵ¥" << endl;
				break;
			}
			}
		}
		else 
			cout << person.work << " " << person.name << ": " << person.timetoa() << " " << "��ϵ¥" << endl;
	}
	cout << endl;
	cout << "���������ַ�����:";
	char ch;
	cin >> ch;
}