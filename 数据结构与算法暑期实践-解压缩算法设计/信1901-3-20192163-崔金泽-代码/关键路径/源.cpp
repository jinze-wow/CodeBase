#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

#define MAXSIZE 100     //顺序栈存储空间的初始分配量
#define MVNum 100         //最大顶点数

/*栈的表示和基本操作*/
struct Stack //栈的定义
{
	int* base;
	int* top;
	int stacksize;
};

//初始化栈
void IntiStack(Stack& s)
{
	s.base = new int[MAXSIZE];
	s.top = s.base;
	s.stacksize = MAXSIZE;
}

//入栈
void Push(Stack& s, int e)
{
	if (s.top - s.base != s.stacksize)    //栈未满
		*s.top++ = e;           //元素e压入栈顶，栈顶指针加1
}

//出栈
void Pop(Stack& s, int& e)
{
	if (s.top != s.base)
		e = *--s.top;         //栈顶指针减1，将栈顶元素赋给e
}

/*图的邻接表存储表示*/

//边结点
struct ArcNode
{
	int adjvex;             //该边所指向的顶点的位置
	ArcNode* nextarc;
	int weight;             //设置边的权值类型为整型
};

//顶点(表头结点)信息
struct VNode
{
	char data;             //定义结点的数据类型为char型
	ArcNode* firstarc;     //指向第一条依附该顶点的边的指针
};

//定义图
struct OLGraph
{
	VNode vertices[MVNum];  //顶点(表头结点)信息
	int vexnum, arcnum;     //图的当前顶点数和边数
};

//返回在图G中顶点U的位置
int LocateVex(OLGraph G, VNode u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == u.data)
			return i;          //第一个点从0开始算起
	}
}


/*采用邻接表创建有向图*/
void CreateGraph(OLGraph& G)
{
	cout << "请依次输入总顶点数和总边数：";
	cin >> G.vexnum >> G.arcnum;//vexnum图的顶点数  arcnum：图的边数
	//输入各点，构造表头结点表
	cout << "请依次输入各结点的名称（用空格作为间隔）：";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;    //firstarc 指向第一条依附该顶点的边的指针
		G.vertices[i].firstarc = NULL;   //初始化表头结点的指针域为NULL
	}
	//输入各边，构造邻接表
	for (int i = 0; i < G.arcnum; i++)
	{
		VNode v1, v2;
		int weight;
		cout << "请输入第" << i + 1 << "个边的起始点、终止点和权值：";
		cin >> v1.data >> v2.data >> weight;
		int m = LocateVex(G, v1); //返回在图G中顶点U的位置
		int n = LocateVex(G, v2);
		ArcNode* p = new ArcNode; 
		p->adjvex = n;       //邻接点序号为n
		p->weight = weight;
		//将结点P插入到顶点Vm的后边的第一个
		p->nextarc = G.vertices[m].firstarc;//firstarc:指向第一条依附该顶点的边的指针
		G.vertices[m].firstarc = p;
	}

}
//求出各顶点的入度存入数组indegree中
void FindIndegree(OLGraph G, int indegree[])
{
	for (int i = 0; i < G.vexnum; i++)
	{
		indegree[i] = 0;
		ArcNode* p = new ArcNode;
		for (int j = 0; j < G.vexnum; j++)
		{
			p = G.vertices[j].firstarc;
			while (p != NULL)
			{
				if (p->adjvex == i) //adjvex：该边所指向的顶点的位置
					(indegree[i])++;
				p = p->nextarc;
			}
		}
	}
}




/*拓扑排序判断是否为AOE-网 (1) 选择一个入度为0的顶点并输出之；
						 (2) 从网中删除此顶点及所有出边。*/
bool TopologicalSort(OLGraph G, int topo[])
{
	int* indegree = new int[G.vexnum];
	Stack s;
	int i;
	FindIndegree(G, indegree);           //求出各顶点入度
	IntiStack(s);
	for (i = 0; i < G.vexnum; i++) //入栈
		if (!indegree[i]) Push(s, i);
	int m = 0;                            //对输出顶点计数
	while (s.top != s.base)    //栈非空
	{
		Pop(s, i);                  //栈顶顶点出栈
		topo[m] = i;                 //出栈顶点保存在拓扑数组中
		++m;
		ArcNode* p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			int k = p->adjvex;		      //adjvex：该边所指向的顶点的位置
			indegree[k]--;                //每一个邻接点入度减1
			if (indegree[k] == 0) Push(s, k);   //入度减为0则入栈
			p = p->nextarc;
		}
	}
	if (m < G.vexnum) return false;
	else return true;
}

/*关键路径算法实现*/
void CriticalPath(OLGraph G)
{
	int topo[MAXSIZE];
	int* ve = new int[G.vexnum];
	int* vl = new int[G.vexnum];
	cout << endl;
	if (!TopologicalSort(G, topo))                    //若不是AOE-图，直接退出
	{
		cout << "该有向图不是AOE-网。" << endl;
		return;
	}
	else
		cout << "该有向图是AOE-网。" << endl;
	int n = G.vexnum;
	int i;
	for (i = 0; i < n; i++) ve[i] = 0;       //初始化最早发生时间为0

										   //按拓扑排序次序求每个事件发生的最早时间
	for (i = 0; i < n; i++)
	{
		int k = topo[i];
		ArcNode* p = G.vertices[k].firstarc;
		while (p != NULL)
		{
			int j = p->adjvex;
			if (ve[j] < ve[k] + p->weight)
				ve[j] = ve[k] + p->weight;
			p = p->nextarc;
		}
	}

	for (i = 0; i < n; i++) vl[i] = ve[n - 1];        //初始化每件事情发生的最早时间是ve[n-1]

													//按拓扑排序的逆序求每件事情发生的最迟时间
	for (i = n - 1; i >= 0; i--)
	{
		int k = topo[i];
		ArcNode* p = G.vertices[k].firstarc;
		while (p != NULL)
		{
			int j = p->adjvex;
			if (vl[k] > (vl[j] - p->weight))
				vl[k] = vl[j] - p->weight;
			p = p->nextarc;
		}
	}

	//判断每一个事件是否为关键活动,路径长度最长的路径就叫做 关键路径
	cout << endl;
	cout << "该AOE-图中的关键路径信息如下：" << endl;
	char map[100], map1[100];
	int x = 0, dat = 0;
	for (i = 0; i < n; i++)
	{
		ArcNode* p = G.vertices[i].firstarc;
		while (p != NULL) {
			{
				int j = p->adjvex;
				int l = vl[j] - p->weight;
				int e = ve[i];
				if (e == l)
				{
					map[x] = G.vertices[i].data;
					map1[x] = G.vertices[j].data;
					dat = dat + p->weight;
					cout << G.vertices[i].data << "--" << G.vertices[j].data << "   路径长度为：" << p->weight << endl;
					x++;
				}
		}
			p = p->nextarc;
		}

	}
	int t = 0;
	cout << endl;
	while (t < x - 1)
	{
		cout << map[t] << "->";
		t++;
	}
	cout << map[t] << "->" << map1[t] << "   路径长度为：" << dat << endl;
}

void Critical_Path()
{
	OLGraph G;
	CreateGraph(G);
	CriticalPath(G);
}
int main() {
	Critical_Path();
}
