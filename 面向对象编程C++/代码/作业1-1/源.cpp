#include <iostream>
using namespace std;
#include <math.h>
#define N 3.14
void main()
{
	float a, b, c;
	int num;
	cout << "求圆形周长和面积" << endl;
		cout << "请输入圆的半径：";
		cin >> a;
		if (a <= 0) cout << "您输入的数值不正确！" << endl;
		else
		{
			cout << "圆的面积为：" << N * a * a << endl;
			cout << "圆的周长为:" << 2 * N * a << endl;
		}
	
	
}