//��1000�������е����������C�̸�Ŀ¼�ļ�Prime.txt�У�
//ÿһ��ֻ���һ�������������������ļ�һ������
//�޽��� 2021/5/16
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main()
{
	ofstream x("D:\\��ѧ\\�����\\c++\\����\\ʵ��5-2\\Prime.txt", ios::out);//ֱ������c�̸�Ŀ¼Ȩ�޲���,�����������������Ŀ¼
	int i, j;
	for (i = 1; i <= 1000; i++)
	{
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (i == j)
			x << i << endl;//������ļ���prime.txt���������
	}
	x.close();
	return 0;
}
