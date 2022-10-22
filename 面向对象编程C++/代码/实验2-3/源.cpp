/*首先定义点类，应包含 x，y 坐标数据成员，坐标获取及设置函数、
显示函数和面积计算函数等成员函数等； 以点类为基类派生圆类，
增加表示半径的数据成员，半径获取及设置函数、
周长计算函数、重载显示函数和面积计算函数等；*/
//崔金泽 2021/4/10
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
    ~Point() {  //析构函数
        cout << "Destructor called" << endl;
    }

    float getX() {
        cout << "x坐标为：" << x << endl;
        return 0;
    }
    float getY() {
        cout << "y坐标为：" << y << endl;
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
        cout << "圆的半径为：" << r << endl;
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
    cout << "面积:" << c << endl;
}
void Circle::calculate2()
{
    double d;
    d = 3.14 * 2 * r;
    cout << "周长:" << d << endl;
}



int main()
{
    
    float a, b, r;
    cout << "请输入xy坐标值";
    cin >> a >> b ;
    Point p1(a, b);
    p1.getX();
    p1.getY();
    cout << "请输入圆的半径";
    cin >> r;
    Circle c(a, b, r);
    c.calculate();
    c.calculate2();
}
