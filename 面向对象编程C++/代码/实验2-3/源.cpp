/*���ȶ�����࣬Ӧ���� x��y �������ݳ�Ա�������ȡ�����ú�����
��ʾ������������㺯���ȳ�Ա�����ȣ� �Ե���Ϊ��������Բ�࣬
���ӱ�ʾ�뾶�����ݳ�Ա���뾶��ȡ�����ú�����
�ܳ����㺯����������ʾ������������㺯���ȣ�*/
//�޽��� 2021/4/10
#include <iostream>
#include <cstring>
#include<math.h>
using namespace std;

class Point
{
private:
    float a, b, x, y;
public:
    Point(float x, float y);
    ~Point() {  //��������
        cout << "Destructor called" << endl;
    }

    float getX() {
        cout << "x����Ϊ��" << x << endl;
        return 0;
    }
    float getY() {
        cout << "y����Ϊ��" << y << endl;
        return 0;
    }

    
};
class Circle :public Point
{
private:
    double r;
    double c;
public:
    Circle(double i, double j, double k);
    float getr(){
        cout << "Բ�İ뾶Ϊ��" << r << endl;
        return 0;
    }
    void calculate();
    void calculate2();
   
};

Circle::Circle(double i, double j, double k) :Point(i, j), r(k) {}
Point::Point(float a, float b)
{
    x = a;
    y = b;
}

void Circle::calculate()
{
    c = 3.14 * r * r;
    cout << "���:" << c << endl;
}
void Circle::calculate2()
{
    double d;
    d = 3.14 * 2 * r;
    cout << "�ܳ�:" << d << endl;
}



int main()
{
    
    float a, b, r;
    cout << "������xy����ֵ";
    cin >> a >> b ;
    Point p1(a, b);
    p1.getX();
    p1.getY();
    cout << "������Բ�İ뾶";
    cin >> r;
    Circle c(a, b, r);
    c.calculate();
    c.calculate2();
}
