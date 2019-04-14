#pragma once
#include "MyUtil.h"

using namespace std;

class road;

typedef struct roadNode
{
	int id; //��·Id
	int length;//��·����
	int speedLimit;//��·����ٶ�����
	int laneNum;//������Ŀ

	int startNode;//��·���
	int endNode;//�յ�
	bool isDoubly;//�Ƿ�˫��0������   1��˫��

	roadNode(vector<int>& temp)
	{
		int i = 0;
		id = temp[i++];
		length = temp[i++];
		speedLimit = temp[i++];
		laneNum = temp[i++];
		startNode = temp[i++];
		endNode = temp[i++];
		isDoubly = static_cast<bool>(temp[i]);
	}

}roadInfo;

class road
{
public:
	road();
	~road();

	void init(vector<int>& temp);

	roadInfo* info;
};
