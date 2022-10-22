//有一元二次方程ax2 + bx + c = 0，其一般解为
//x1, 2 = (-b±sqrt(b2 - 4ac)) / 2a, 但若a = 0或b2 - 4ac < 0时，用此公式出错。编程序，从键盘输入a, b, c的值，求x1和x2。如果a = 0或b2 - 4ac < 0，输出出错信息。
#include <iostream> 
#include <cmath>
	using namespace std;
void main()
{
	float a, b, c, disc;
	cout << "please input a, b, c:";
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6) cerr << "a is equal to zero, error!" << endl;
	else if ((disc = b * b - 4 * a * c) < 0)
		cerr << "disc = b * b - 4 * a * c < 0" << endl;
	else
	{
		cout << "x1 = " << (-b + sqrt(disc)) / (2 * a) << endl;
		cout << "x2 = " << (-b - sqrt(disc)) / (2 * a) << endl;
	}
}
