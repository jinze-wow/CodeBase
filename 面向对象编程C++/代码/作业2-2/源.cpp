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
    ~Point() {  //��������
        cout << "Destructor called" << endl;
    }
    Point(float a, float b,float c) {

        x = a;
        y = b;
        z = c;
    }

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

void Point::calculate()
{
    double s;
    s = sqrt(x * x +y*y+z*z) ;
    cout << "�õ㵽ԭ��ľ���Ϊ��" << s<<endl;
}
int main()
{
    int a, b, c;
    cout << "������xyz����ֵ";
    cin >> a >> b >> c;
    Point p1;
    p1.getX();
    p1.getY();
    p1.getZ();
    p1.calculate();
}