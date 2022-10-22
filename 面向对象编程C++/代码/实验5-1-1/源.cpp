//��һԪ���η���ax2 + bx + c = 0����һ���Ϊ
//x1, 2 = (-b��sqrt(b2 - 4ac)) / 2a, ����a = 0��b2 - 4ac < 0ʱ���ô˹�ʽ��������򣬴Ӽ�������a, b, c��ֵ����x1��x2�����a = 0��b2 - 4ac < 0�����������Ϣ��
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
