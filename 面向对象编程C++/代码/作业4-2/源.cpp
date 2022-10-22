//对类Point（要求Point类有构造函数，能查看坐标的成员函数，及两个表示坐标的数据成员）重载++（自增）
//，--（自减）运算符，要求同时重载前置和后置的形式。
#include <iostream>
using namespace std;

class Point
{
	
public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
public:                   

	void show() { cout << "(" << x << ", " << y << ")" << endl; }    // 输出点的坐标

public:                     //运算符函数重载

	Point operator ++ ();      // 前置， ++i\--i
	Point operator -- ();

	Point operator ++(int);     // 后置,i++\i--
	Point operator --(int);
private:
	int x;
	int y;
};

Point Point:: operator ++ () // 前置
{
	Point c;
	c.x = x + 1;
	c.y = y + 1;

	x += 1;
	y += 1;

	return c;
}

Point Point::operator --() // 前置
{
	Point c;
	c.x = x - 1;
	c.y = y - 1;

	x -= 1;
	y -= 1;

	return c;
}

Point Point::operator ++(int) // 后置
{
	Point c;
	c.x = x;
	c.y = y;

	x += 1;
	y += 1;

	return c;
}

Point Point::operator --(int) // 后置
{
	Point c;
	c.x = x;
	c.y = y;

	x -= 1;
	y -= 1;

	return c;
}

int main()
{
	Point c;
	Point c1(1, 1);
	Point c2(2, 2);

	cout << "两个点初始坐标:" << endl;
	cout << "c1:"; c1.show();
	cout << "c2:"; c2.show();


	cout << "后置运算后的坐标:" << endl;
	c = c1++;
	cout << "c1++= "; c1.show();
	c = c2--;
	cout << "c2--= "; c2.show();


	cout << "前置运算后的坐标:" << endl;
	c = ++c1;
	cout << "++c1= "; c1.show();
	c = --c2;
	cout << "--c2= "; c2.show();

	return 0;
}
