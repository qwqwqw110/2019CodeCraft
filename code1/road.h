#pragma once
#include "MyUtil.h"

class road;

extern int roadIdOffset;

extern int carOverNum;  //������ɵĳ����������ѵ���Ŀ�ĵ�
extern int waitStartCarNum;   //�ڳ���ȴ������ĳ�����Ŀ

extern int carNum;   //���г�������Ŀ

typedef struct roadNode
{
	int id; //��·Id
	int length;//��·����
	int speedLimit;//��·����ٶ�����
	int laneNum;//������Ŀ

	int startNode;//��·���
	int endNode;//�յ�
	bool isDoubly;//�Ƿ�˫��0������   1��˫��

	int roadCarNum;//·�ϳ�������Ŀ

	roadNode(vector<int>& temp)
	{
		int i = 0;
		id = temp[i++];
		length = temp[i++];
		speedLimit = temp[i++];
		laneNum = temp[i++];
		startNode = temp[i++];
		endNode = temp[i++];
		isDoubly = temp[i++];
		roadCarNum = 0;
	}

}roadInfo;

class road
{
public:
	road();
	~road();

	void init(vector<int>& temp);
	
	roadInfo get();//���ص�·��Ϣ
	void runonRoad();//������ʻ

	//ͬ����ʻ�ĵ�·���ϰ���������ͬһ�����ĳ����� tempΪĳ������ȫ���ĳ���
	void runByRoadRule(vector<shared_ptr<car>>& temp);

	void flushStatus();

	//�ж��ܷ�����·��
	bool canJoin(int carId, int crossId);

	roadInfo* info;

	//����ָ�벻��ʼ��ʱΪ��
	shared_ptr<car> oneCarPtr;//ָ��һ����
	vector<shared_ptr<car>> carsinLane;//һ�������ϵĳ���

	/*
	
	
	*/

	vector<vector<shared_ptr<car>>> carOneRoadPositive;
	vector<vector<shared_ptr<car>>> carOneRoadNegative;
	
};
