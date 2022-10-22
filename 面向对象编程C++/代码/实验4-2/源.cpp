/*分别使用3个函数模板实现对T[n]中的数据进行输入、排序（算法自选）、输出，
主函数中针对不同类型数据进行测试，在实验报告中附上每个例子的结果截图。*/
//崔金泽 2021/5/15
#include<iostream>
#include<string.h> 
#include<algorithm>
using namespace std;

template <typename T> void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
template <typename T> int getsize(T& array)
{
	return sizeof(array) / sizeof(array[0]);
}

template <typename T> void maopao(T& a,int n)
{
	int len = n;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j]) 
			swap(a[i], a[j]);
		}
}


template <typename T> void qsort(T& a, int low, int high)
{
	if (low >= high) return;
	int i = low + 1, j = high;
	int key = a[low];
	while (1)
	{
		while (1) {
			if (key < a[j] && j>low)
				j--;
			else break;
		}
		while (1) {
			if (a[i] < key && i < high)
				i++;
			else break;
		}
		if (i >= j) break;
		else swap(a[i], a[j]);

	}
	swap(a[low], a[j]);
	qsort(a, low, j - 1);
	qsort(a, j + 1, high);
}

template <typename T> int selectionSort(T &arr,int x)
{
	int len = x;
	int minIndex, temp,i,j;
	for (i = 0; i < len - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < len; j++) {
			if (arr[j] < arr[minIndex]) {    // 寻找最小的数
				minIndex = j;                // 将最小数的索引保存
			}
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	return 0;
}
int main()
{
	int a[100];
	int n, i = 0;
	cout << "采用冒泡排序：" << endl;
	cout << "输入数据的个数n:"<<endl;
	cin >> n;
	cout << "请输入数据" << endl;
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	cout << "其元素分别为：";
	for(i=0;i<n;i++){ cout << a[i] << ' '; }
	
	cout << "对该数组排序" << endl;
	cout << "输出排序后的数组：" << endl;;
	maopao(a,n);
	for (int i = 0; i < n; i++)
		cout << a[i] << "   ";
	cout << endl << endl;

	cout << "采用快速排序" << endl;
	cout << "原始数组为字符型数组b"<<endl;
	cout << "输入数据的个数n:";
	int m;
	cin >> m;
	cout << "请输入数据" << endl;
	double b[99];
	for (i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	cout << "对该数组的排序" << endl;
	qsort(b, 0, m - 1);
	cout << "输出排序后的结果" << endl;
	for (int i = 0; i < m; i++)
		cout << b[i] << "   ";
	cout << endl << endl;

	cout << "采用选择排序" << endl;
	cout << "输入数据的个数x";
	int x;
	cin >> x;
	cout << "请输入数据" << endl;
	int arr[99];
	for (i = 0; i < x; i++)
	{
		cin >> arr[i];
	}

	cout << "对该数组排序" << endl;
	selectionSort(arr,x);
	cout << "输出排序后结果：" << endl;
	for (int i = 0; i < x; i++)
		cout << arr[i] << "   ";
	cout << endl;
	return 0;
}