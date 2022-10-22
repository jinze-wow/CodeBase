#include <iostream>
#include "Circle.h"
using namespace std;
int main()
{ 
	int a;
	Circle c1;
	cout << "请输入圆的半径，按回车结束" << endl;
	cin >> a;
	c1.set_radius(a);
	c1.calculate();
	return 0;
}
