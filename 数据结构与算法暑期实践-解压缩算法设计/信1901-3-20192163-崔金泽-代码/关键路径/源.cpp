#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

#define MAXSIZE 100     //˳��ջ�洢�ռ�ĳ�ʼ������
#define MVNum 100         //��󶥵���

/*ջ�ı�ʾ�ͻ�������*/
struct Stack //ջ�Ķ���
{
	int* base;
	int* top;
	int stacksize;
};

//��ʼ��ջ
void IntiStack(Stack& s)
{
	s.base = new int[MAXSIZE];
	s.top = s.base;
	s.stacksize = MAXSIZE;
}

//��ջ
void Push(Stack& s, int e)
{
	if (s.top - s.base != s.stacksize)    //ջδ��
		*s.top++ = e;           //Ԫ��eѹ��ջ����ջ��ָ���1
}

//��ջ
void Pop(Stack& s, int& e)
{
	if (s.top != s.base)
		e = *--s.top;         //ջ��ָ���1����ջ��Ԫ�ظ���e
}

/*ͼ���ڽӱ�洢��ʾ*/

//�߽��
struct ArcNode
{
	int adjvex;             //�ñ���ָ��Ķ����λ��
	ArcNode* nextarc;
	int weight;             //���ñߵ�Ȩֵ����Ϊ����
};

//����(��ͷ���)��Ϣ
struct VNode
{
	char data;             //���������������Ϊchar��
	ArcNode* firstarc;     //ָ���һ�������ö���ıߵ�ָ��
};

//����ͼ
struct OLGraph
{
	VNode vertices[MVNum];  //����(��ͷ���)��Ϣ
	int vexnum, arcnum;     //ͼ�ĵ�ǰ�������ͱ���
};

//������ͼG�ж���U��λ��
int LocateVex(OLGraph G, VNode u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == u.data)
			return i;          //��һ�����0��ʼ����
	}
}


/*�����ڽӱ�������ͼ*/
void CreateGraph(OLGraph& G)
{
	cout << "�����������ܶ��������ܱ�����";
	cin >> G.vexnum >> G.arcnum;//vexnumͼ�Ķ�����  arcnum��ͼ�ı���
	//������㣬�����ͷ����
	cout << "������������������ƣ��ÿո���Ϊ�������";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;    //firstarc ָ���һ�������ö���ıߵ�ָ��
		G.vertices[i].firstarc = NULL;   //��ʼ����ͷ����ָ����ΪNULL
	}
	//������ߣ������ڽӱ�
	for (int i = 0; i < G.arcnum; i++)
	{
		VNode v1, v2;
		int weight;
		cout << "�������" << i + 1 << "���ߵ���ʼ�㡢��ֹ���Ȩֵ��";
		cin >> v1.data >> v2.data >> weight;
		int m = LocateVex(G, v1); //������ͼG�ж���U��λ��
		int n = LocateVex(G, v2);
		ArcNode* p = new ArcNode; 
		p->adjvex = n;       //�ڽӵ����Ϊn
		p->weight = weight;
		//�����P���뵽����Vm�ĺ�ߵĵ�һ��
		p->nextarc = G.vertices[m].firstarc;//firstarc:ָ���һ�������ö���ıߵ�ָ��
		G.vertices[m].firstarc = p;
	}

}
//������������ȴ�������indegree��
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
				if (p->adjvex == i) //adjvex���ñ���ָ��Ķ����λ��
					(indegree[i])++;
				p = p->nextarc;
			}
		}
	}
}




/*���������ж��Ƿ�ΪAOE-�� (1) ѡ��һ�����Ϊ0�Ķ��㲢���֮��
						 (2) ������ɾ���˶��㼰���г��ߡ�*/
bool TopologicalSort(OLGraph G, int topo[])
{
	int* indegree = new int[G.vexnum];
	Stack s;
	int i;
	FindIndegree(G, indegree);           //������������
	IntiStack(s);
	for (i = 0; i < G.vexnum; i++) //��ջ
		if (!indegree[i]) Push(s, i);
	int m = 0;                            //������������
	while (s.top != s.base)    //ջ�ǿ�
	{
		Pop(s, i);                  //ջ�������ջ
		topo[m] = i;                 //��ջ���㱣��������������
		++m;
		ArcNode* p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			int k = p->adjvex;		      //adjvex���ñ���ָ��Ķ����λ��
			indegree[k]--;                //ÿһ���ڽӵ���ȼ�1
			if (indegree[k] == 0) Push(s, k);   //��ȼ�Ϊ0����ջ
			p = p->nextarc;
		}
	}
	if (m < G.vexnum) return false;
	else return true;
}

/*�ؼ�·���㷨ʵ��*/
void CriticalPath(OLGraph G)
{
	int topo[MAXSIZE];
	int* ve = new int[G.vexnum];
	int* vl = new int[G.vexnum];
	cout << endl;
	if (!TopologicalSort(G, topo))                    //������AOE-ͼ��ֱ���˳�
	{
		cout << "������ͼ����AOE-����" << endl;
		return;
	}
	else
		cout << "������ͼ��AOE-����" << endl;
	int n = G.vexnum;
	int i;
	for (i = 0; i < n; i++) ve[i] = 0;       //��ʼ�����緢��ʱ��Ϊ0

										   //���������������ÿ���¼�����������ʱ��
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

	for (i = 0; i < n; i++) vl[i] = ve[n - 1];        //��ʼ��ÿ�����鷢��������ʱ����ve[n-1]

													//�����������������ÿ�����鷢�������ʱ��
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

	//�ж�ÿһ���¼��Ƿ�Ϊ�ؼ��,·���������·���ͽ��� �ؼ�·��
	cout << endl;
	cout << "��AOE-ͼ�еĹؼ�·����Ϣ���£�" << endl;
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
					cout << G.vertices[i].data << "--" << G.vertices[j].data << "   ·������Ϊ��" << p->weight << endl;
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
	cout << map[t] << "->" << map1[t] << "   ·������Ϊ��" << dat << endl;
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
