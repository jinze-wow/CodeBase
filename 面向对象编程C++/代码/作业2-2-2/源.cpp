#include <iostream>
#include <cstring>
#include<math.h>
using namespace std;

class Point
{
private:
    float a, b, c, x, y, z;
public:
    Point()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    Point(float x, float y, float z);
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
    void calculate();
};

Point::Point(float x, float y, float z)
{
    a = x;
    b = y;
    c = z;
}
void Point::point2()
{

}
void Point::calculate()
{
    double s;
    s = sqrt(x * x + y * y + z * z);
    cout << "�õ㵽ԭ��ľ���Ϊ��" << s << endl;
}
int main()
{
    int a, b, c;
    cout << "������xyz����ֵ";
    cin >> a >> b >> c;
    Point p1;
    p1.point1(a, b, c);
    p1.point2();
    p1.getX();
    p1.getY();
    p1.getZ();
    p1.calculate();
}