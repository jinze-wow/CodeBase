//��Բ�������дһ�����ڶ���ĳ������ݳ�ԱΪ�뾶(r)������Ϊ˽�г�Ա��Ҫ���ó�Ա����ʵ���ڼ���
//������Բ�뾶������Բ��������Բ����������ܣ�Ҫ��������Ա���������������������ⶨ�塣
#include <iostream>
using namespace std;
#define PI 3.14
#include "Circle.h"
void Circle::set_radius(int a)
{
	x = a;
}
void Circle::calculate()
{
	double s;
	s = x * x * PI;
	cout << "area:"<< s;
}
