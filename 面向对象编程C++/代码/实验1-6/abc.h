#pragma once
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
    void display()
    {
        cout << "x=" << x << ",y" << y << ",z" << z<< endl;
    }
};