//引用传递求一组数中的最大值和最小值
#include<iostream>
using namespace std;
int main()
{
	int number[10] = { 1,3,4,9,3,6,11,10,12,25 }, max, min;
	max = number[0];
	min = number[0];
	for (int i = 1; i < 10; i++)
	{
		if(number[i] > max)max = number[i];
		if (number[i] < min)min = number[i];
	}
	cout << "最大值为：" << max << endl;
	cout << "最小值为：" << min << endl;
	return 0;
}