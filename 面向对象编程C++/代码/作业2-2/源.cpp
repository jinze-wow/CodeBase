#include <iostream>
#include <cstring>
#include<math.h>
using namespace std;

class Point
{
private:
    float a,b,c,x, y,z;
public:
    Point() {};
    ~Point() {  //析构函数
        cout << "Destructor called" << endl;
    }
    Point(float a, float b,float c) {

        x = a;
        y = b;
        z = c;
    }

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
    void calculate();
};

void Point::calculate()
{
    double s;
    s = sqrt(x * x +y*y+z*z) ;
    cout << "该点到原点的距离为：" << s<<endl;
}
int main()
{
    int a, b, c;
    cout << "请输入xyz坐标值";
    cin >> a >> b >> c;
    Point p1;
    p1.getX();
    p1.getY();
    p1.getZ();
    p1.calculate();
}