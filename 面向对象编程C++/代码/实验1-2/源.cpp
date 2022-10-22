//用C++语言编写函数，使用函数重载，能求两个整数的最大数、三个整数的最大数、四个整数的最大数。 
//崔金泽 2021/4/10

#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		cout << "最大值为 : " << a << endl;
	else 
		cout << "最大值为 : " << b << endl;
	return 0;
}
int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c) 
			cout << "最大值为 : " << a << endl;
		else 
			cout << "最大值为 : " << c << endl;
	}
	else
	{
		if (b > c) 
			cout << "最大值为 : " << b << endl;
		else 
			cout << "最大值为 : " << c << endl;
	}
	return 0;
}
int max(int a[4])
{
	int i, max = a[0];
	for (i = 0; i < 3; i++)
	{
		if (max < a[i]) max = a[i];
	}
	cout << "最大值为 : " << max << endl;
	return 0;
}
void main()
{
	int i, x, a[4];
	int n;
	cout << "请输入想输入数字的个数: " << endl;
	cin >> n;
	cout << "请输入数据: " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 2)
		x = max(a[0], a[1]);
	else if (n==3)
		x = max(a[0], a[1], a[2]);
	else if (n == 4)
		x = max(a);
}
