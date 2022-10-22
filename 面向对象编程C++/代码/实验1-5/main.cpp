//下面的程序中有错误，通过跟踪调试或者断点调试的方法，找出错误，
//解释错误原因，给出修改方法，修改正确后给出三个测试结果。
//崔金泽 2021/4/10
#include "rect.h"
#include <iostream>
using namespace std;
void main()
{
	rect r1(1,2);
	cout << "Its area is " << r1.area() << endl;
	rect r2(1, 2);
	cout << "Its area is " << r2.area() << endl;
}
