//���ļ�f1.txt�ж�ȡ���ݣ������մ�С�����˳�����У�
//������������Ļ�У�ͬʱ����f2.txt�ļ��С�
//�޽���2021/5/16
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> //�����㷨
using namespace std;
int main()
{
	
	ifstream x("D:\\��ѧ\\�����\\c++\\����\\ʵ��5-4\\f1.txt", ios::out);
	string s;//�����ı������洢����
	int n=0 ;
	while (x >> s) {//�����ļ���
		cout << s;
		n=n+1;
	}
	vector<double>score(n);
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	cout << endl;
	sort(score.begin(), score.end());//��С�������� 
	ofstream file("D:\\��ѧ\\�����\\c++\\����\\ʵ��5-4\\f2.txt", ios_base::out);
	for (int i = 0; i < n; i++)
	{
		file << score[i] << " ";
		
	}
	file.close();
}
