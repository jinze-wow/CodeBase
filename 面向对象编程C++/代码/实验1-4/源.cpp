//�ȶ���һ�����࣬����Ϊpoint���������궨��Ϊ˽�г�Ա������������г�Ա������ɵ�����롢
//���������x���ꡢ����y����ͷ���z���ꡣ
//���������ж�������һ�����������ܹ��������꣬������꣬���������ԭ��ľ��롣
//�޽��� 2021/4/10
#include <iostream>
#include <cstring>
#include<math.h>
using namespace std;

class Point
{
private:
    float a, b, c, x, y, z;
public:
    Point();
    ~Point() {  //��������
        cout << "Destructor called" << endl;
    }
    void point1(float a, float b, float c) {

        x = a;
        y = b;
        z = c;
    }
    void point2();

    float getX() {
        cout << "x����Ϊ��" << x << endl;
        return 0;
    }
    float getY() {
        cout << "y����Ϊ��" << y << endl;
        return 0;
    }
    float getZ() {
        cout << "z����Ϊ��" << z << endl;
        return 0;
    }
    //void calculate();
};
Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}
void Point::point2()
{

}
/*void Point::calculate()
{
    double s;
    s = sqrt(x * x + y * y + z * z);
    cout << "�õ㵽ԭ��ľ���Ϊ��" << s << endl;
}*/
int main()
{
    Point p1;
    int a, b, c;
    Point* p = &p1;
   /* p->getX();
    p->getY();
    p->getZ();*/

    cout << "������xyz����ֵ";
    cin >> a >> b >> c;
    p1.point1(a, b, c);
    p1.point2();
    p1.getX();
    p1.getY();
    p1.getZ();
    //p1.calculate();
}