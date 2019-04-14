#include "MyUtil.h"
//#include "Floyd.h"

extern vector<cross> vcross;
extern vector<road> vroad;
extern vector<car> vcar;

//��ID�������±��ӳ��
map<int, int> roadIdtoIndex;
map<int, int> crossIdtoIndex;
map<int, int> carIdtoIndex;


MyUtil::MyUtil()
{
}


MyUtil::~MyUtil()
{
}

void initIdMap()
{
	//��ʼ��roadIdtoIndex����roadID��ѯ��id������phero�е��±꣩
	for (int i = 1; i < vroad.size(); i++)
	{
		roadIdtoIndex[vroad[i].info->id] = i;
	}
	for (int i = 1; i < vcar.size(); i++)
	{
		carIdtoIndex[vcar[i].info->id] = i;
	}
	for (int i = 1; i < vcross.size(); i++)
	{
		crossIdtoIndex[vcross[i].info->id] = i;
	}
}



/*
 * ÿ����·�Ͼ������ٳ�
 *
 * ÿ��¥�ڹ����ٳ�
 *
 *ÿ������answer
 *
 */
vector<int> carNumPerRoad;
int carN=0;

void answerAnalyze(vector<passRoad> &answer)
{
    carNumPerRoad.resize(vroad.size());
    carN++;

    for(auto t: answer)
    {
        carNumPerRoad[roadIdtoIndex[t.roadId]] ++;
    }
    if(carN == vcar.size()-1)
    {
        for(int i=0; i<carNumPerRoad.size(); ++i)
        {
            cout<<"road "<<i<<"  "<<carNumPerRoad[i]<<endl;
        }
    }

}


/*
 * ͳ�������ĳ�������
 * ��ͬ�ٶ��ж�������
 * ͳ�Ʒ���ʱ��
 *
 *carsΪ���ٶ������ķ�������
 */

void carNumAnalyze(vector<car> &cars)
{
    int lastV = cars[0].info->speedLimit;
    int num=0;
    int minT= cars[0].info->timePlan;
    int maxT= cars[0].info->timePlan;
    int priorityNum=0;
    int presetNum=0;
    for(auto c : cars)
    {
        if(c.info->speedLimit == lastV)
            num++;
        else
        {
            cout<<"V "<<lastV<<"  "<<num<<endl;
            lastV=c.info->speedLimit;
            num=0;
        }

        if(minT>c.info->timePlan)
            minT=c.info->timePlan;

        if(maxT<c.info->timePlan)
            maxT=c.info->timePlan;
        if(c.info->preset)
            presetNum++;
        if(c.info->priority)
            priorityNum++;

    }
    cout<<"V "<<lastV<<"  "<<num<<endl;

    cout<<"maxTime CAR "<<maxT<<endl;
    cout<<"minTime CAR "<<minT<<endl;

    cout<<"priority CAR num "<<priorityNum<<endl;
    cout<<"preset CAR num "<<presetNum<<endl;
    cout<<"total CAR num "<<cars.size()<<endl;

}


/*
 * ͳ�Ƶ�·����
 * ͳ�Ƴ�����Ŀ
 * ͳ�Ƴ�����˫��
 *
 * ����ٶȣ�����ٶ�
 *
 *roadsΪ��·����
 */

void roadAnalyze(vector<road> &roads)
{
    double averLen=0;
    double averLane=0;
    vector<int> laneNum(10, 0);
    int danxiang=0;
    int sumLen=0;
    int sumLane=0;
    int minV=vroad[1].info->speedLimit;
    int maxV = vroad[1].info->speedLimit;
    for(int i=1; i<roads.size(); ++i)
    {
        sumLen+=vroad[i].info->length;
        sumLane+=vroad[i].info->laneNum;
        laneNum[vroad[i].info->laneNum]++;
        if(vroad[i].info->isDoubly)
            danxiang++;

        if(minV>vroad[i].info->speedLimit)
            minV = vroad[i].info->speedLimit;
        if(maxV<vroad[i].info->speedLimit)
            maxV = vroad[i].info->speedLimit;

    }
    averLane = sumLane/(double)(vroad.size()-1);
    averLen = sumLen / (double)(vroad.size()-1);

    cout<<"road num "<<vroad.size()-1<<endl;
    cout<<"road low V "<<minV<<endl;
    cout<<"road high V "<<maxV<<endl;
    cout<<"road aver LaneNum "<<averLane<<endl;
    cout<<"road aver length "<<averLen<<endl;
    cout<<"danxiang lanenum "<<danxiang<<endl;

}




