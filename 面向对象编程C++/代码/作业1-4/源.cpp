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
cout << faction() << endl;//a��b���
cout << faction(x,y) << endl;//��xy��ֵ�������
cout << faction(x) << endl;//x�����b���
}

