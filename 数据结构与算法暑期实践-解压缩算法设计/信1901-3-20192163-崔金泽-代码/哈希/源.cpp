#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string>
using namespace std;


#define M 40                 //��ϣ����
#define D 37                 //��ϣ���еĴ�����
#define NULLKEY "/wu"        //��ϣ����û�����ݵı�

bool iscreate;

struct hushtable {
	string key;        //�ؼ�����
	int count;          //̽�������
};

int Ser(hushtable* m, string x)//���ң�xΪ��Ҫ���ҵ�����
{
	int H0, pos = x[0] + x[1];//pos��x1��x2��ASC����֮��
	int Hi;
	H0 = pos % D;//H0��ӳ������ֵ
	if (m[H0].key == NULLKEY)//ӳ��Ĺؼ�����Ϊ��
		return -1;
	else if (m[H0].key == x)//ӳ��Ĺؼ������������x
		return H0;
	else//��Ϊ���ֲ���x
	{
		for (int i = 1; i < M; ++i)//����Ϊ1���β���
		{
			Hi = (H0 + i) % M;
			if (m[Hi].key == NULLKEY) return -1;
			else if (m[Hi].key == x) return Hi;
		}
		return -1;
	}
}

void CompASL(hushtable *ha)//���ҳɹ�ʱ��ƽ�����ҳ���
{
	int i;
	int s = 0, n = 0;
	for (i = 0; i < M; i++)
		if (ha[i].key != NULLKEY)//�ǿ�
		{
			s = s + ha[i].count;  //ha[i].count��ʼ��1
			n++;
		}
	cout << " ���ҳɹ���ASL="<< s * 1.0 <<endl;
}

void showtable(hushtable * r)//��ӡ��ϣ��
{
	for (int i = 0; i < M; i++)
		if (r[i].key != NULLKEY)
		{
			cout << "λ��:" << i << "," << "ֵ:" << r[i].key << "		";
		}
	cout << endl;
}

void menuHush()
{
	cout << endl;
	cout << "��ѡ�����¹��ܣ�" << endl;
	cout << "1.������ϣ��" << endl;
	cout << "2.����ĳ������" << endl;
	cout << "3.������ҳɹ�ʱ��ƽ�����ҳ���" << endl;
	cout << "4.�˳�����" << endl;
}

int Hush()
{
	hushtable r[M];
	int m;
	for (int i = 0; i < M; i++)//��ʼ��
	{
		r[i].key = NULLKEY;
	}
	menuHush();
	cin >> m;
	while (m != 4)
	{
		if (m == 1)
		{
			int ra;
			cout << "������Ҫ�����ı�����ݸ���" << endl;
			cin >> ra;
			for (int m = 0; m < ra; m++)
			{
				string x;
				cout << "����������Ҫ���������" << endl;
				cin >> x;
				int H0, pos = x[0] + x[1];//pos��ASC���룬����12,1��ASC��49��+2��ASC��50��=99����x1��x2��asc�������
				cout << "pos:" << pos << endl;
				int Hi;
				H0 = pos % D;//Ϊ�˷�ֹ���ݹ���99>40)������������ӳ�䵽��0-40֮��
				cout << "H0:" << H0 << endl;
				if (r[H0].key == NULLKEY)//�����ϣ���λ��Ϊ����д��
				{
					r[H0].key = x;
					r[H0].count++;
				}
				else
					for (int i = 1; i < M; i++)//��ֵ��˳�ӵ���һ��
					{
						Hi = (H0 + i) % M;
						cout << "Hi:" << Hi << endl;
						if (r[Hi].key == NULLKEY)//Ϊ����д�����ݣ�count���֮ǰ+1
						{
							r[Hi].key = x;//key�Ǵ�С��count��λ��
							r[H0].count++;
							break;//����for
						}
						else if (r[Hi].key != NULLKEY)//�����Ϊ����λ��+1������ѭ��
						{
							r[H0].count++;
						}
					}
			}
			iscreate = true;
			showtable(r);
			cout << "�������" << endl;
		}
		else if (m == 2 && iscreate)
		{
			string ra;
			cout << "������Ҫ���ҵ�Ԫ�أ�" << endl;
			cin >> ra;
			if (Ser(r, ra) != -1)
				cout << "����ҵ�Ԫ����" << Ser(r, ra) << "λ��" << endl;
			else
				cout << "����ҵ�Ԫ�ز�����" << endl;
		}
		else if (m == 3 && iscreate)
		{
			CompASL(r);
		}
		menuHush();
		cin >> m;
	}
	return 0;
}
int main() {
	Hush();
}