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
	if (P.top == P.base) cout << "ͣ����Ϊ��" << endl;
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
	cout << "�����복�ź�ͣ��ʱ�䣺" << endl;
	cin >> number >> time;
	if (P.stacksize < n)
	{
		CarNode c;
		c.num = number;
		c.time1 = time;
		Push(P, c);
		cout << "�ó�Ӧ��ͣ�ڵ�" << P.stacksize << "�ų���" << endl;

	}
	else
	{
		EnQuene(S, number, time);
		cout << "ͣ��������������ʱͣ�ڱ���ĵ�" << S.length << "��λ��" << endl;

	}
	return 1;
}
Status Leave(Park& P, Park& P1, Shortcut& S) {//����վ�����Ĵ���
	int number, le_time, flag = 1, money, ar_time;
	cout << "�����복�ƺźͳ���ʱ�̣�" << endl;
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
	// ����ͣ�����г�
	if (flag == 0)
	{
		if (S.length != 0)
		{
			//DeQueue(S,w);
			m.time1 = le_time;
			m.num = w->num;
			Push(P, m);
			free(w);
			cout << "���ƺ�Ϊ" << m.num << "�ĳ����ɱ������ͣ����" << endl;
		}
		cout << "ͣ����Ϊ" << money << endl << "�ֱ�ռ�ó�λ��Ϊ" << P.stacksize << endl;
	}
	else cout << "ͣ�����������ƺ�Ϊ" << number << "�ĳ�" << endl;

	return 1;
}
int main() {
	int m = 1;
	cout << "������ͣ����������" << endl;
	cin >> n;
	getchar();
	char flag;//ѡ��
	Park P, Q;
	Shortcut S;
	InitStack(P);
	InitStack(Q);
	InitQuene(S);
	while (m)
	{
		cout << "************ͣ����������� ***********" << endl;
		cout << "��ѡ�������A.ͣ��  D.�뿪  E.�˳�ϵͳ";
		scanf("%c", &flag);

		switch (flag)
		{
		case 'A':
		case 'a':
			Arrival(P, S); break; //������ͣ����
		case 'D':
		case 'd':
			Leave(P, Q, S); break; //���뿪ͣ����
		case 'E':
		case 'e':
			m = 0;
			break;
		default:
			cout << "���������룺";
			break;
		}
		getchar();

	}

	return 0;

}

