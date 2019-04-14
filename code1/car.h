#pragma once

#include "MyUtil.h"

using namespace std;

class car;
extern int carIdOffset;

extern int carOverNum;  //������ɵĳ����������ѵ���Ŀ�ĵ�
extern int waitStartCarNum;   //�ڳ���ȴ������ĳ�����Ŀ

extern int carNum;   //���г�������Ŀ

enum carStatus
{
	waitStart,//�ȴ�����״̬
	run,//��ʻ״̬
	waitCross,//�ȴ�ͨ��·��״̬
	wait,   // �ȴ�״̬
	stop,   //��ֹ״̬
	over,//�����������
			  //��ǰ��������ס�������룩
};

typedef struct carNode
{
	int id;
	int start;//���������ص��Ŀ�ĵ�
	int end;
	int speedLimit;//������������ٶ�����
	int timePlan; //�ƻ�����ʱ��

	int speedCurrent;//������ǰ�ٶ�
	int timeStart; //ʵ�ʳ���ʱ��
	int timeRun;//����������ʱ��

	carStatus status; //������ǰ״̬
	int index;//������ǰλ��
	vector<int> throughRoadId;//���������ĵ�·ID

	//�����ƻ������ĵ�·id     ��ʱû�г�ʼ��������ʹ��floyd�㷨������һ����ʼ·��
	queue<int> planThroughRoadId;  
	//��ǰ��ʻ��·�ͳ����������룩

	carNode(vector<int>& temp)
	{
		int i = 0;
		id = temp[i++];
		start = temp[i++];
		end = temp[i++];
		speedLimit = temp[i++];
		timePlan = temp[i++];
	}
}carInfo;

class car
{
public:
	car();
	~car();

	void init(vector<int>& temp);


	void go();

	//void setStatu(carStatus statu);//���³���״̬
	//void setSpeed(int speed);//�ı䳵����ǰ�ٶȣ�������ʻ����ǰ���ٶȺ�λ��
	
	carInfo get();//���س�����Ϣ
	carInfo* info;//������Ϣ
};
