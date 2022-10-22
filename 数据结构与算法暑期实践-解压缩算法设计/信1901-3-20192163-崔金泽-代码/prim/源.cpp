#include<iostream>
#include<fstream>
using  namespace std;

#define MAX 1000
#define maxset 10000

int graph[MAX][MAX];

int prim(int graph[][MAX], int m)
{
	int lowset[MAX]; //�ڽӱ� ��ʾ��iΪ�յ�ıߵ���СȨֵ
	int mst[MAX]; //Ȩֵ�� ��Ӧlowset[i]����� ��<mst[i],i>��MST��һ���ߣ�
	//��mst[i]=0��ʾ���i����MST����lowset[2]=5��mst[2]=3���Ǵ����2��3�ľ���Ϊ5
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= m; i++) 
	{
		lowset[i] = graph[1][i]; //��ʼ��
		mst[i] = 1;//���е�Ĭ�������V1
	}
	mst[1] = 0; //��1�ڵ�����ڽӱ���
	for (i = 2; i <= m; i++)
	{
		min = maxset;//��min�ȳ�ʼ��Ϊ���
		minid = 0;
		for (j = 2; j <= m; j++)
		{
			if (lowset[j] < min && lowset[j] != 0)//Ѱ��lowset����С����һ��
			{
				min = lowset[j];
				minid = j;
			}
		}
		cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;
		//mst[minid]��ֵ��Ϊ��һ����
		sum += min;
		lowset[minid] = 0;//�����֮�󽫸õ��lowset��0
		for (j = 2; j <= m; j++)//����mst��lowset����
		{//�����V3���룬��Ҫ�������飬minid=3��
			
			/*lowcost[2]=6��lowcost[3]=1��lowcost[4]=5��lowcost[5]=*��lowcost[6]=*
			mst[2]=1��mst[3]=1��mst[4]=1��mst[5]=1��mst[6]=1
			V3����֮��
			lowcost[2]=5��lowcost[3]=0��lowcost[4]=5��lowcost[5]=6��lowcost[6]=4
			mst[2]=3��mst[3]=0��mst[4]=1��mst[5]=3��mst[6]=3
			*/

			if (graph[minid][j] < lowset[j])//V3����֮��lowcost[5]=*��lowcost[6]=*���������޴�
			{//���ӽ�ȥ��graph[3][i]
				lowset[j] = graph[minid][j];//��V3�����ĵ��·��Ȩֵ
				mst[j] = minid; //δ����ĵ��mst[]���ǵ���3
			}
		}
	}
	return sum;
}

int main()
{
	int i, j, k, m, n;
	int x, y, set;
	cout << "����ͼ�Ķ������ͱ���(�ո����)��" << endl;
	cin >> m >> n;
	//��ʼ��ͼG
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = maxset;//graph��һ����ά����
		}
	}
	cout << "����" << n << "���ߵĿ�ʼ�������ڵ㣬Ȩֵ(�ո����):" << endl;
	//����ͼG
	for (k = 1; k <= n; k++)
	{
		cin >> i >> j >> set;
		graph[i][j] = set;//����graph[2][3]=10����2��3�ľ�����10
		graph[j][i] = set;
	}

	//�����С������
	set = prim(graph, m);
	//�����СȨֵ��
	cout << "��СȨֵ��=" << set << endl;
	system("pause");
	return 0;
}