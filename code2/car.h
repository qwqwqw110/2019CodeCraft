#pragma once

#include "MyUtil.h"

using namespace std;

class car;

typedef struct passroad {
    int roadId;
    bool isPositive;//1????????0??????
}passRoad;


typedef struct carNode
{
	int id;
	int start;//���������ص��Ŀ�ĵ�
	int end;
	int speedLimit;//������������ٶ�����
	int timePlan; //�ƻ�����ʱ��

	bool priority;
	bool preset;

    vector<passRoad> throughRoad;//���������ĵ�·ID

	carNode(vector<int>& temp)
	{
		int i = 0;
		id = temp[i++];
		start = temp[i++];
		end = temp[i++];
		speedLimit = temp[i++];
		timePlan = temp[i++];
		priority = static_cast<bool>(temp[i++]);
		preset = static_cast<bool>(temp[i]);
	}
}carInfo;

class car
{
public:
	car();
	~car();

	void init(vector<int>& temp);

	carInfo* info;//������Ϣ

};
