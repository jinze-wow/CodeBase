/*����Point��Ҫ��Point���й��캯�����ܲ鿴����ĳ�Ա������
��������ʾ��������ݳ�Ա����Ϊ�䶨����Ԫ����ʵ�����ء�+������*/
//�޽��� 2021/5/8
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
    friend Point operator+(Point& pt, int nOffset);
    friend Point operator+(int nOffset, Point& pt);
    ~Point() { } //��������
};
Point operator+(Point& pt, int nOffset)
{
    Point p = pt;
    p.x += nOffset;
    p.y += nOffset;

    return p;
}

Point operator+(int nOffset, Point& pt)
{
    Point p = pt;
    p.x += nOffset;
    p.y += nOffset;

    return p;
}
void Point::showPoint()
{
    cout << "x=" << x << "  y=" << y << endl;
}
int main()
{
    Point p(2, 3);
    p.showPoint();
    p = p + 5;
    p.showPoint();
    p = p + 10; 
    p.showPoint();
    return 0;
}