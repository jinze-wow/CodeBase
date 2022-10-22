//求圆面积，编写一个基于对象的程序，数据成员为半径(r)，定义为私有成员，要求用成员函数实现在键盘
//上输入圆半径，计算圆面积、输出圆面积三个功能，要求三个成员函数在类内声明，在类外定义。
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
