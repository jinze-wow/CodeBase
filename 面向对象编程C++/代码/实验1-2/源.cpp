//��C++���Ա�д������ʹ�ú������أ����������������������������������������ĸ�������������� 
//�޽��� 2021/4/10

#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		cout << "���ֵΪ : " << a << endl;
	else 
		cout << "���ֵΪ : " << b << endl;
	return 0;
}
int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c) 
			cout << "���ֵΪ : " << a << endl;
		else 
			cout << "���ֵΪ : " << c << endl;
	}
	else
	{
		if (b > c) 
			cout << "���ֵΪ : " << b << endl;
		else 
			cout << "���ֵΪ : " << c << endl;
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
	cout << "���ֵΪ : " << max << endl;
	return 0;
}
void main()
{
	int i, x, a[4];
	int n;
	cout << "���������������ֵĸ���: " << endl;
	cin >> n;
	cout << "����������: " << endl;
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
