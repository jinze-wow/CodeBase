//使用函数模板，实现求两个数，三个数的最小值。
//主函数中针对不同类型数据进行测试（实现显示实例化和隐式实例化）。

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
	cout << "请输入同类型两个或三个数(若输入2个数则在第三个数的位置填0)：" << endl;
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
