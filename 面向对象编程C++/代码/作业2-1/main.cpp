#include <iostream>
#include "Circle.h"
using namespace std;
int main()
{ 
	int a;
	Circle c1;
	cout << "������Բ�İ뾶�����س�����" << endl;
	cin >> a;
	c1.set_radius(a);
	c1.calculate();
	return 0;
}
