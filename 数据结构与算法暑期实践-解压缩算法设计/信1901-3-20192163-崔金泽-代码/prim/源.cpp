#include<iostream>
#include<fstream>
using  namespace std;

#define MAX 1000
#define maxset 10000

int graph[MAX][MAX];

int prim(int graph[][MAX], int m)
{
	int lowset[MAX]; //邻接表 表示以i为终点的边的最小权值
	int mst[MAX]; //权值表 对应lowset[i]的起点 边<mst[i],i>是MST的一条边，
	//当mst[i]=0表示起点i加入MST，如lowset[2]=5，mst[2]=3就是代表从2到3的距离为5
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= m; i++) 
	{
		lowset[i] = graph[1][i]; //初始化
		mst[i] = 1;//所有点默认起点是V1
	}
	mst[1] = 0; //将1节点加入邻接表中
	for (i = 2; i <= m; i++)
	{
		min = maxset;//将min先初始化为最大
		minid = 0;
		for (j = 2; j <= m; j++)
		{
			if (lowset[j] < min && lowset[j] != 0)//寻找lowset中最小的那一个
			{
				min = lowset[j];
				minid = j;
			}
		}
		cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;
		//mst[minid]的值即为上一个点
		sum += min;
		lowset[minid] = 0;//点加入之后将该点的lowset置0
		for (j = 2; j <= m; j++)//更新mst和lowset数组
		{//加入点V3加入，需要更新数组，minid=3，
			
			/*lowcost[2]=6，lowcost[3]=1，lowcost[4]=5，lowcost[5]=*，lowcost[6]=*
			mst[2]=1，mst[3]=1，mst[4]=1，mst[5]=1，mst[6]=1
			V3加入之后：
			lowcost[2]=5，lowcost[3]=0，lowcost[4]=5，lowcost[5]=6，lowcost[6]=4
			mst[2]=3，mst[3]=0，mst[4]=1，mst[5]=3，mst[6]=3
			*/

			if (graph[minid][j] < lowset[j])//V3加入之后，lowcost[5]=*，lowcost[6]=*不再是无限大
			{//连接进去的graph[3][i]
				lowset[j] = graph[minid][j];//与V3相连的点的路径权值
				mst[j] = minid; //未加入的点的mst[]都是等于3
			}
		}
	}
	return sum;
}

int main()
{
	int i, j, k, m, n;
	int x, y, set;
	cout << "无向图的顶点数和边数(空格隔开)：" << endl;
	cin >> m >> n;
	//初始化图G
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = maxset;//graph是一个二维数组
		}
	}
	cout << "输入" << n << "条边的开始，结束节点，权值(空格隔开):" << endl;
	//构建图G
	for (k = 1; k <= n; k++)
	{
		cin >> i >> j >> set;
		graph[i][j] = set;//例如graph[2][3]=10代表2到3的距离是10
		graph[j][i] = set;
	}

	//求解最小生成树
	set = prim(graph, m);
	//输出最小权值和
	cout << "最小权值和=" << set << endl;
	system("pause");
	return 0;
}