//ʹ�ú���ģ�壬ʵ����������������������Сֵ��
//����������Բ�ͬ�������ݽ��в��ԣ�ʵ����ʾʵ��������ʽʵ��������

#include<iostream> 
using namespace std;
template<typename T>
T min(T a, T b, T c)
{
	if (c != 0)
	{
		T min;
		min = a < b ? a : b;
		min = min < c ? min : c;
		return min;
	}
	else
	{ 
		T min;
		min = a < b ? a : b;
		return min;
	}
}
int main()
{
	cout << "������ͬ����������������(������2�������ڵ���������λ����0)��" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	if (typeid(a) == typeid(int))
	{
		cout << min(a, b, c) << endl;
	}
	else if (typeid(a) == typeid(double))
	{
		cout << min(a, b, c) << endl;
	}
	else if (typeid(a) == typeid(char))
	{
		cout << min<char>(a, b, c) << endl;
	}
}
