/*输入OFF文件，其中OFF文件保存n个点的坐标，第一行为点的个数，
从第二行开始，每一行为一个点的三个坐标，例如，cube.OFF文件如下:
8
0 0 0
1 0 0
0 1 0
1 1 0
0 0 1
1 0 1
0 1 1
1 1 1
写一个程序能读入OFF文件，并将输入的点的坐标输出到屏幕上，
每行只输出一个点的坐标，要求OFF文件的名称由程序中输入。*/
//崔金泽 2021/5/16
#include<iostream>
#include<fstream>
using namespace std;
int main() 
{
    ofstream x("D:\\大学\\大二下\\c++\\代码\\实验5-2\\OFF.txt", ios::out);
    int a[3];
    int i,n,j=0;
    char name;
    /*cout << "请输入文件名称";
    cin >> name;
    char oldname[] = "OFF.txt";
    char newname[] = "zuobiao.txt";
    rename(oldname, newname);//重命名*/
    cout << "请输入坐标的个数n";
    cin >> n;
    x << n << endl;
    cout << "请输入坐标";
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
    ifstream y("D:\\大学\\大二下\\c++\\代码\\实验5-2\\OFF.txt", ios::in);
    string s;
    while (y >> s )
    {
        cout  << s << endl;
    }
    y.close();
    return 0;
}