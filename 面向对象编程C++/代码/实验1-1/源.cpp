//在主函数中输入一个一维数组，调用函数maxAndMin得到数组元素中的最大值与最小值
//崔金泽 2021/4/10
#include <iostream>
using namespace std;
#define  SIZE 10

void maxAndMin(int a[], int& maximum, int& minimum)
{
	maximum = a[0];
	minimum = a[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (a[i] > maximum)
			maximum = a[i];
		if (a[i] < minimum)
			minimum = a[i];
	}
}

int main()
{
	int numbers[SIZE], maxValue, minValue, i;
	cout << "Please input " << SIZE << " numbers:";
	for (i = 0; i < SIZE; i++)
		cin >> numbers[i];

	maxAndMin(numbers, maxValue, minValue);

	cout << "The maximum is: " << maxValue << endl;
	cout << "The minimum is: " << minValue << endl;

	return 0;
}
