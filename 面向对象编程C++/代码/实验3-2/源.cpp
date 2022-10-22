/*对类Point（要求Point类有构造函数，能查看坐标的成员函数，
及两个表示坐标的数据成员）
重载++（自增），--（自减）运算符，要求同时重载前缀和后缀的形式；*/
//崔金泽 2021/5/8
#include <iostream>

using namespace std;

class Point
{
private:
    int a, b, x, y;
public:
    Point(int a, int b) {
        x = a;
        y = b;
    }
    void showPoint();
    Point& operator++();  //前置
    Point operator++ (int); //后置
    Point& operator--();  //前置
    Point operator--(int); //后置
    ~Point() { } //析构函数
};
Point& Point::operator++()//前置++ 
{
    ++x, ++y;
    return *this;
}
Point Point::operator++(int)//后置++ 
{
    x++, y++;
    return *this;
}
Point& Point::operator--()//前置-- 
{
    --x, --y;
    return *this;
}
Point Point::operator--(int)//后置--
{
    x--, y--;
    return *this;
}
void Point::showPoint()
{
    cout << "x=" << x << "  y=" << y << endl;
}
int main()
{
    Point p(2, 3);
    p.showPoint();
    cout << "前置++：";
    ++p;
    p.showPoint();
    cout << "后置++：";
    p++;
    p.showPoint();
    cout << "前置--：";
    --p;
    p.showPoint();
    cout << "后置--：";
    p--;
    p.showPoint();
    return 0;
}