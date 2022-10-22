//将1000以内所有的素数输出到C盘根目录文件Prime.txt中，
//每一行只输出一个素数。将程序和输出文件一起打包。
//崔金泽 2021/5/16
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main()
{
	ofstream x("D:\\大学\\大二下\\c++\\代码\\实验5-2\\Prime.txt", ios::out);//直接输入c盘根目录权限不够,所以输出到代码所在目录
	int i, j;
	for (i = 1; i <= 1000; i++)
	{
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (i == j)
			x << i << endl;//向磁盘文件″prime.txt″输出数据
	}
	x.close();
	return 0;
}
