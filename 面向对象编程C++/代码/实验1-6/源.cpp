/*先定义一个点类，类名为point，用课堂教师演示的方式添加类，
即类的定义要在头文件中，另外有一个描述类成员函数实现的cpp文件，
还有一个主函数的文件。
1)	将其三维坐标定义为私有成员，通过构造函数为其初始化，
并在构造函数和析构函数中有输出语句，以便于从运行结果看出构造函数和
析构函数的运行。
2)	写三个构造函数用于重载，包含一个默认构造函数。
3)	定义一个对象指针，并通过该指针完成对点对象坐标的输入和输出。
4)	定义对象数组，观察构造函数和析构函数调用的顺序。*/

//崔金泽 2021/4/10
#include <iostream>
#include <cstring>
#include<math.h>
#include "abc.h"
using namespace std;



int main()
{
    Point p1;
    int a, b, c;
    Point* p = &p1;
    p->display();
    cout << "请输入xyz坐标值";
    cin >> a >> b >> c;
    p1.point1(a, b, c);
    Point k, m(1).n(1, 2);//定义Point对象k,m,n， 调用构造函数初始化
    m.display();//显示坐标
    return 0;
}