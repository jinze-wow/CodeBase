/*����OFF�ļ�������OFF�ļ�����n��������꣬��һ��Ϊ��ĸ�����
�ӵڶ��п�ʼ��ÿһ��Ϊһ������������꣬���磬cube.OFF�ļ�����:
8
0 0 0
1 0 0
0 1 0
1 1 0
0 0 1
1 0 1
0 1 1
1 1 1
дһ�������ܶ���OFF�ļ�����������ĵ�������������Ļ�ϣ�
ÿ��ֻ���һ��������꣬Ҫ��OFF�ļ��������ɳ��������롣*/
//�޽��� 2021/5/16
#include<iostream>
#include<fstream>
using namespace std;
int main() 
{
    ofstream x("D:\\��ѧ\\�����\\c++\\����\\ʵ��5-2\\OFF.txt", ios::out);
    int a[3];
    int i,n,j=0;
    char name;
    /*cout << "�������ļ�����";
    cin >> name;
    char oldname[] = "OFF.txt";
    char newname[] = "zuobiao.txt";
    rename(oldname, newname);//������*/
    cout << "����������ĸ���n";
    cin >> n;
    x << n << endl;
    cout << "����������";
    while(j<3*n)
    {
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        x << a[i] << " ";
    }
    x << endl;
    i = 0; j = j + 3;
    }
    x.close();
    ifstream y("D:\\��ѧ\\�����\\c++\\����\\ʵ��5-2\\OFF.txt", ios::in);
    string s;
    while (y >> s )
    {
        cout  << s << endl;
    }
    y.close();
    return 0;
}