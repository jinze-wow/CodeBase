/*����Point��Ҫ��Point���й��캯�����ܲ鿴����ĳ�Ա������
��������ʾ��������ݳ�Ա��
����++����������--���Լ����������Ҫ��ͬʱ����ǰ׺�ͺ�׺����ʽ��*/
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
    Point& operator++();  //ǰ��
    Point operator++ (int); //����
    Point& operator--();  //ǰ��
    Point operator--(int); //����
    ~Point() { } //��������
};
Point& Point::operator++()//ǰ��++ 
{
    ++x, ++y;
    return *this;
}
Point Point::operator++(int)//����++ 
{
    x++, y++;
    return *this;
}
Point& Point::operator--()//ǰ��-- 
{
    --x, --y;
    return *this;
}
Point Point::operator--(int)//����--
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
    cout << "ǰ��++��";
    ++p;
    p.showPoint();
    cout << "����++��";
    p++;
    p.showPoint();
    cout << "ǰ��--��";
    --p;
    p.showPoint();
    cout << "����--��";
    p--;
    p.showPoint();
    return 0;
}