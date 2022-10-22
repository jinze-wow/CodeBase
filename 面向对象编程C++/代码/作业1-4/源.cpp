#include<iostream>
using namespace std;
#include<math.h>
int faction(int a = 3,int b=4)
{
	int c;
	c = a * b;
	return c;
}
void main(void)
{
	int x = 5, y = 6;
cout << faction() << endl;//a和b相乘
cout << faction(x,y) << endl;//将xy的值带入相乘
cout << faction(x) << endl;//x带入和b相乘
}

