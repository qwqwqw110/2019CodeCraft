#include "MyUtil.h"
extern vector<car> vcar;
car::car()
{
}


car::~car()
{
}

void car::init(vector<int>& temp)
{
	info = new carInfo(temp);

	info->status = waitStart;

	//if (temp[0] == tempAnswer[0])
	//{
	//	for (int i = 0; i < tempAnswer.size(); i++)
	//	{
	//		info->planThroughRoadId.push(tempAnswer[i]);
	//	}
	//}
}

void car::go()
{
}

//void setStatu(carStatus statu)//���³���״̬
//{
//
//}
//carStatus getStatu()//���س���״̬
//{
//
//}
//int getTime()//���س���������ʱ��
//{
//
//}