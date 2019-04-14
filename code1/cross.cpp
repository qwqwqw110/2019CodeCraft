#include "MyUtil.h"

extern vector<cross> vcross;
extern vector<road> vroad;
extern vector<car> vcar;
cross::cross()
{
}


cross::~cross()
{
}

void cross::init(vector<int>& temp)
{
	info = new crossInfo(temp);
	sort(info->roads.begin(), info->roads.end());
	sort(info->garage.begin(), info->garage.end());
}

/*
����·��
*/

void cross::runCross()
{
	int nextRoad = 0;
	int roadId = 0;
	for (int j = 0; j < 4; j++)
	{
		roadId = info->roads[j];
		if (roadId > 0)
		{
			shared_ptr<road> roadPtr = make_shared<road>(vroad[roadId - roadIdOffset]);
			shared_ptr<vector<vector<shared_ptr<car>>>> tempRoadPtr;
			//������·����ĳ��·�ĳ�·,���������֧��,�ҵ�·�ڵĳ��ж����Ƿ��ǵȴ�ͨ��·��״̬
			if (roadPtr->info->endNode == info->id)
			{
				tempRoadPtr = make_shared<vector<vector<shared_ptr<car>>>>(roadPtr->carOneRoadPositive);
			}
			//������·����ĳ��·�ĳ�·���Ƿ����֧��
			else if (roadPtr->info->startNode == info->id && roadPtr->info->isDoubly)
			{
				tempRoadPtr = make_shared<vector<vector<shared_ptr<car>>>>(roadPtr->carOneRoadNegative);
			}


			//tempRoadPtr ��ʾ�ڸ�·��Ҫ����ͨ��·�ڵ�ĳ����·��������򳵵�
			int laneNum = tempRoadPtr->size();
			shared_ptr<vector<shared_ptr<car>>> carsLanePtr;    //ָ��ĳ�������ϵĳ���ָ��
			for (int i = 1; i < laneNum; i++)
			{

				carsLanePtr = make_shared<vector<shared_ptr<car>>>(tempRoadPtr->at(i));
				int carNum = carsLanePtr->size();
				if (carNum > 0)
				{
					for (int k = 0; k < carNum; k++)
					{
						if (carsLanePtr->at(k)->info->status == carStatus::waitCross)
						{

						
						}
					}
				}

			}
		}
	}
}

/*
�����ڳ����еĳ���������·
*/
void cross::runGarageCaratCross(int currentTime)
{
	int carNum = info->garage.size();   //��ǰ·�ڳ���ĳ�����Ŀ
	int carId = 0;
	
	if (carNum > 0)
	{
		for (int i = 0; i < carNum; i++)
		{
			
			carId = info->garage[i];
			//�������ó��ĳ���ʱ��,�����������
			if (vcar[carId-carIdOffset].info->start >= currentTime)
			{
				info->readyGo.push_back(carId);
			}
			
		}

		//����Ҫ�����ĳ��������򰴳���id�������
		if (info->readyGo.size() > 0)
		{
			int nextRoad = 0;
			sort(info->readyGo.begin(), info->readyGo.end());
			for (int j = 0; j < info->readyGo.size(); j++)
			{
				/*
				����ʱ���չ滮�õ�·�߻������ѡ���·�߳���
				*/
				nextRoad = vcar[info->readyGo[j] - carIdOffset].info->planThroughRoadId.front();
				/*
				�ж�Ҫ����ĳ����Ƿ���λ�ÿ��Լ��룬������룬
				��ȥ���ƻ�·���еĸ�·�Σ�
				��ʵ����ʻ·���м����·��
				*/
				if (vroad[nextRoad - roadIdOffset].canJoin(info->readyGo[j], info->id))
				{

					vcar[info->readyGo[j] - carIdOffset].info->planThroughRoadId.pop();
					vcar[info->readyGo[j] - carIdOffset].info->throughRoadId.push_back(nextRoad);
					waitStartCarNum--;
				}
			}
		}
	}
}
