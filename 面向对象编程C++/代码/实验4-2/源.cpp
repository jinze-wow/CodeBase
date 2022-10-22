/*�ֱ�ʹ��3������ģ��ʵ�ֶ�T[n]�е����ݽ������롢�����㷨��ѡ���������
����������Բ�ͬ�������ݽ��в��ԣ���ʵ�鱨���и���ÿ�����ӵĽ����ͼ��*/
//�޽��� 2021/5/15
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
			if (arr[j] < arr[minIndex]) {    // Ѱ����С����
				minIndex = j;                // ����С������������
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
	cout << "����ð������" << endl;
	cout << "�������ݵĸ���n:"<<endl;
	cin >> n;
	cout << "����������" << endl;
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	cout << "��Ԫ�طֱ�Ϊ��";
	for(i=0;i<n;i++){ cout << a[i] << ' '; }
	
	cout << "�Ը���������" << endl;
	cout << "������������飺" << endl;;
	maopao(a,n);
	for (int i = 0; i < n; i++)
		cout << a[i] << "   ";
	cout << endl << endl;

	cout << "���ÿ�������" << endl;
	cout << "ԭʼ����Ϊ�ַ�������b"<<endl;
	cout << "�������ݵĸ���n:";
	int m;
	cin >> m;
	cout << "����������" << endl;
	double b[99];
	for (i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	cout << "�Ը����������" << endl;
	qsort(b, 0, m - 1);
	cout << "��������Ľ��" << endl;
	for (int i = 0; i < m; i++)
		cout << b[i] << "   ";
	cout << endl << endl;

	cout << "����ѡ������" << endl;
	cout << "�������ݵĸ���x";
	int x;
	cin >> x;
	cout << "����������" << endl;
	int arr[99];
	for (i = 0; i < x; i++)
	{
		cin >> arr[i];
	}

	cout << "�Ը���������" << endl;
	selectionSort(arr,x);
	cout << "������������" << endl;
	for (int i = 0; i < x; i++)
		cout << arr[i] << "   ";
	cout << endl;
	return 0;
}