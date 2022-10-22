#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string>
using namespace std;


#define M 40                 //哈希表长度
#define D 37                 //哈希表中的待除余
#define NULLKEY "/wu"        //哈希表中没有内容的表

bool iscreate;

struct hushtable {
	string key;        //关键字域
	int count;          //探查次数域
};

int Ser(hushtable* m, string x)//查找，x为需要查找的数组
{
	int H0, pos = x[0] + x[1];//pos是x1与x2的ASCⅡ码之和
	int Hi;
	H0 = pos % D;//H0是映射后的数值
	if (m[H0].key == NULLKEY)//映射的关键字域为空
		return -1;
	else if (m[H0].key == x)//映射的关键字域是输入的x
		return H0;
	else//不为空又不是x
	{
		for (int i = 1; i < M; ++i)//步进为1依次查找
		{
			Hi = (H0 + i) % M;
			if (m[Hi].key == NULLKEY) return -1;
			else if (m[Hi].key == x) return Hi;
		}
		return -1;
	}
}

void CompASL(hushtable *ha)//查找成功时的平均查找长度
{
	int i;
	int s = 0, n = 0;
	for (i = 0; i < M; i++)
		if (ha[i].key != NULLKEY)//非空
		{
			s = s + ha[i].count;  //ha[i].count初始是1
			n++;
		}
	cout << " 查找成功的ASL="<< s * 1.0 <<endl;
}

void showtable(hushtable * r)//打印哈希表
{
	for (int i = 0; i < M; i++)
		if (r[i].key != NULLKEY)
		{
			cout << "位置:" << i << "," << "值:" << r[i].key << "		";
		}
	cout << endl;
}

void menuHush()
{
	cout << endl;
	cout << "请选择以下功能：" << endl;
	cout << "1.创建哈希表" << endl;
	cout << "2.查找某个名字" << endl;
	cout << "3.输出查找成功时的平均查找长度" << endl;
	cout << "4.退出程序" << endl;
}

int Hush()
{
	hushtable r[M];
	int m;
	for (int i = 0; i < M; i++)//初始化
	{
		r[i].key = NULLKEY;
	}
	menuHush();
	cin >> m;
	while (m != 4)
	{
		if (m == 1)
		{
			int ra;
			cout << "请输入要创建的表的数据个数" << endl;
			cin >> ra;
			for (int m = 0; m < ra; m++)
			{
				string x;
				cout << "请依次输入要放入的数据" << endl;
				cin >> x;
				int H0, pos = x[0] + x[1];//pos是ASCⅡ码，输入12,1的ASCⅡ（49）+2的ASCⅡ（50）=99，将x1和x2的ascⅡ码相加
				cout << "pos:" << pos << endl;
				int Hi;
				H0 = pos % D;//为了防止数据过大（99>40)，把所有数据映射到了0-40之中
				cout << "H0:" << H0 << endl;
				if (r[H0].key == NULLKEY)//如果哈希表该位置为空则写入
				{
					r[H0].key = x;
					r[H0].count++;
				}
				else
					for (int i = 1; i < M; i++)//有值则顺延到下一个
					{
						Hi = (H0 + i) % M;
						cout << "Hi:" << Hi << endl;
						if (r[Hi].key == NULLKEY)//为空则写入数据，count相比之前+1
						{
							r[Hi].key = x;//key是大小，count是位置
							r[H0].count++;
							break;//跳出for
						}
						else if (r[Hi].key != NULLKEY)//如果不为空则位置+1，继续循环
						{
							r[H0].count++;
						}
					}
			}
			iscreate = true;
			showtable(r);
			cout << "创建完成" << endl;
		}
		else if (m == 2 && iscreate)
		{
			string ra;
			cout << "请输入要查找的元素：" << endl;
			cin >> ra;
			if (Ser(r, ra) != -1)
				cout << "你查找的元素在" << Ser(r, ra) << "位置" << endl;
			else
				cout << "你查找的元素不存在" << endl;
		}
		else if (m == 3 && iscreate)
		{
			CompASL(r);
		}
		menuHush();
		cin >> m;
	}
	return 0;
}
int main() {
	Hush();
}