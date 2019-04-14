#pragma once

#include "MyUtil.h"


typedef struct passroad {
	int roadId;
	bool isPositive;//1��������0������
}passRoad;


class Floyd
{
public:
	double** twoWayMap;
	double** wayAttributes;
	Floyd(int r, int c);
	~Floyd();
	//����˫��ͼ
	void creatMap();

	//��ʼ������Ȩ��
	void initWeights();

	//���¸���Ȩ��
	void updataWeights(vector<passRoad> path, int carSpeed);

	//ȷ�����������·��
	vector<passRoad> getShortestPathCore(int startId, int endId,int **dist);
	vector<passRoad> getShortestPath(int startId, int endId, int carSpeedLimit);
	void scheduling(string ansPath);
	void getPath(queue<int> &pathNode, int res, int des, int **dist);
private:
	int row;
	int col;
};




