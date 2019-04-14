#pragma once

#include "MyUtil.h"
using namespace std;

class cross;

typedef struct crossNode
{
	int id;//·��ID
	vector<int> roads;//��·�������ӵĵ�·ID    ��0����
	int direction[4];

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

	crossInfo* info;

};
