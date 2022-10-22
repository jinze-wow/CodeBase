#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
typedef int Status;
typedef struct Car1
{
	int num;
	int time1;
} CarNode;
typedef struct
{
	CarNode* base;
	CarNode* top;
	int stacksize;
}Park;
typedef struct Car2
{
	int num;
	int time1;
	struct Car2* next;
} *CarPtr;
typedef struct
{
	CarPtr front;
	CarPtr rear;
	int length;
}Shortcut;
Status InitStack(Park& P)
{
	P.base = (CarNode*)malloc(n * sizeof(Car1));
	if (!P.base) exit(0);
	P.top = P.base;
	P.stacksize = 0;
	return true;
}
Status Push(Park& P, CarNode e)
{
	*P.top++ = e;
	++P.stacksize;
	return true;
}
Status Pop(Park& P, CarNode& e)
{
	if (P.top == P.base) cout << "停车场为空" << endl;
	else
	{
		e = *--P.top;
		--P.stacksize;
	}
	return 1;
}
Status InitQuene(Shortcut& S)
{
	S.front = S.rear = (CarPtr)malloc(sizeof(Car2));
	if (!S.front || !S.rear) exit(0);
	S.front->next = NULL;
	S.length = 0;
	return 1;
}
Status EnQuene(Shortcut& S, int number, int time)
{
	CarPtr p;
	p = (CarPtr)malloc(sizeof(Car2));
	if (!p) exit(0);
	p->num = number;
	p->time1 = time;
	p->next = NULL;
	S.rear->next = p;
	S.rear = p;
	++S.length;
	return 1;
}
Status Arrival(Park& P, Shortcut& S)
{
	int number, time;
	cout << "请输入车号和停车时间：" << endl;
	cin >> number >> time;
	if (P.stacksize < n)
	{
		CarNode c;
		c.num = number;
		c.time1 = time;
		Push(P, c);
		cout << "该车应该停在第" << P.stacksize << "号车道" << endl;

	}
	else
	{
		EnQuene(S, number, time);
		cout << "停车场已满，请暂时停在便道的第" << S.length << "个位置" << endl;

	}
	return 1;
}
Status Leave(Park& P, Park& P1, Shortcut& S) {//对离站车辆的处理
	int number, le_time, flag = 1, money, ar_time;
	cout << "请输入车牌号和出场时刻：" << endl;
	cin >> number >> le_time;
	CarNode e, m;
	CarPtr w;
	while (P.stacksize)
	{
		Pop(P, e);
		if (e.num == number)
		{
			flag = 0;
			money = (le_time - e.time1) * 2;
			ar_time = e.time1;
			break;
		}
		Push(P1, e);
	}
	while (P1.stacksize)
	{
		Pop(P1, e);
		Push(P, e);
	}
	// 车从停车场中出
	if (flag == 0)
	{
		if (S.length != 0)
		{
			//DeQueue(S,w);
			m.time1 = le_time;
			m.num = w->num;
			Push(P, m);
			free(w);
			cout << "车牌号为" << m.num << "的车已由便道进入停车场" << endl;
		}
		cout << "停车费为" << money << endl << "现被占用车位数为" << P.stacksize << endl;
	}
	else cout << "停车场不存在牌号为" << number << "的车" << endl;

	return 1;
}
int main() {
	int m = 1;
	cout << "请输入停车场容量：" << endl;
	cin >> n;
	getchar();
	char flag;//选项
	Park P, Q;
	Shortcut S;
	InitStack(P);
	InitStack(Q);
	InitQuene(S);
	while (m)
	{
		cout << "************停车场管理程序 ***********" << endl;
		cout << "请选择操作：A.停车  D.离开  E.退出系统";
		scanf("%c", &flag);

		switch (flag)
		{
		case 'A':
		case 'a':
			Arrival(P, S); break; //车进入停车场
		case 'D':
		case 'd':
			Leave(P, Q, S); break; //车离开停车场
		case 'E':
		case 'e':
			m = 0;
			break;
		default:
			cout << "请重新输入：";
			break;
		}
		getchar();

	}

	return 0;

}

