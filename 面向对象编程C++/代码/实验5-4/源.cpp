//从文件f1.txt中读取数据，并按照从小到大的顺序排列，
//将结果输出在屏幕中，同时存入f2.txt文件中。
//崔金泽2021/5/16
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> //排序算法
using namespace std;
int main()
{
	
	ifstream x("D:\\大学\\大二下\\c++\\代码\\实验5-4\\f1.txt", ios::out);
	string s;//创建的变量，存储数据
	int n=0 ;
	while (x >> s) {//输入文件流
		cout << s;
		n=n+1;
	}
	vector<double>score(n);
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	cout << endl;
	sort(score.begin(), score.end());//从小到大排序 
	ofstream file("D:\\大学\\大二下\\c++\\代码\\实验5-4\\f2.txt", ios_base::out);
	for (int i = 0; i < n; i++)
	{
		file << score[i] << " ";
		
	}
	file.close();
}
