//����Point��Ҫ��Point���й��캯�����ܲ鿴����ĳ�Ա��������������ʾ��������ݳ�Ա������++��������
//��--���Լ����������Ҫ��ͬʱ����ǰ�úͺ��õ���ʽ��
#include <iostream>
using namespace std;

class Point
{
	
public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
public:                   

	void show() { cout << "(" << x << ", " << y << ")" << endl; }    // ����������

public:                     //�������������

	Point operator ++ ();      // ǰ�ã� ++i\--i
	Point operator -- ();

	Point operator ++(int);     // ����,i++\i--
	Point operator --(int);
private:
	int x;
	int y;
};

Point Point:: operator ++ () // ǰ��
{
	Point c;
	c.x = x + 1;
	c.y = y + 1;

	x += 1;
	y += 1;

	return c;
}

Point Point::operator --() // ǰ��
{
	Point c;
	c.x = x - 1;
	c.y = y - 1;

	x -= 1;
	y -= 1;

	return c;
}

Point Point::operator ++(int) // ����
{
	Point c;
	c.x = x;
	c.y = y;

	x += 1;
	y += 1;

	return c;
}

Point Point::operator --(int) // ����
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

	cout << "�������ʼ����:" << endl;
	cout << "c1:"; c1.show();
	cout << "c2:"; c2.show();


	cout << "��������������:" << endl;
	c = c1++;
	cout << "c1++= "; c1.show();
	c = c2--;
	cout << "c2--= "; c2.show();


	cout << "ǰ������������:" << endl;
	c = ++c1;
	cout << "++c1= "; c1.show();
	c = --c2;
	cout << "--c2= "; c2.show();

	return 0;
}
