//先定义一个点类，类名为point，将其坐标定义为私有成员，定义五个公有成员函数完成点的输入、
//输出、返回x坐标、返回y坐标和返回z坐标。
//在主程序中定义该类的一个对象，做到能够输入坐标，输出坐标，并且输出到原点的距离。
//崔金泽 2021/4/10
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
    ~Point() {  //析构函数
        cout << "Destructor called" << endl;
    }
    void point1(float a, float b, float c) {

        x = a;
        y = b;
        z = c;
    }
    void point2();

    float getX() {
        cout << "x坐标为：" << x << endl;
        return 0;
    }
    float getY() {
        cout << "y坐标为：" << y << endl;
        return 0;
    }
    float getZ() {
        cout << "z坐标为：" << z << endl;
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
    cout << "该点到原点的距离为：" << s << endl;
}*/
int main()
{
    Point p1;
    int a, b, c;
    Point* p = &p1;
   /* p->getX();
    p->getY();
    p->getZ();*/

    cout << "请输入xyz坐标值";
    cin >> a >> b >> c;
    p1.point1(a, b, c);
    p1.point2();
    p1.getX();
    p1.getY();
    p1.getZ();
    //p1.calculate();
}