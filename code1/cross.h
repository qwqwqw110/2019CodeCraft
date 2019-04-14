#pragma once

#include "MyUtil.h"

class cross;

extern int crossIdOffset;

extern int roadIdOffset;

typedef struct crossNode
{
	int id;//·��ID
	vector<int> roads;//��·�������ӵĵ�·ID    ��0����
	vector<int> garage;//��·�ڳ��⳵��ID     ��0����

	vector<int> readyGo; //����ʱ����Գ����ĳ���������ѡ��������߲�����

	crossNode(vector<int>& temp)
	{
		
		id = temp[0];
		for (int i = 0; i < 4; i++)
			roads.push_back(temp[i+1]);
	}
}crossInfo;

class cross
{
public:
	cross();
	~cross();

	void init(vector<int>& temp);

	void runCross();//��������·�ڵĳ���Ȼ����·�������ӵ�·�ĳ�

	void runGarageCaratCross(int currentTime);//���ȳ����еĳ����ó����еĳ���·

	crossInfo* info;

	
};
