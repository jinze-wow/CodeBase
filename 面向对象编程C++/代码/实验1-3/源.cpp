//定义一个学生类，设计私有数据成员：年龄 int age;姓名 string name;公有成员函数：
//带参数的初始化函数  Input(int a, string str);获取数据成员函数    
//Output();在主函数中定义一个有3个元素的对象数组并分别输入，然后输出对象数组的信息。
//崔金泽 2021/4/10
#include <iostream>
using namespace std;

class Student
{
public:
	int age;
	string name;
	int Input(int a, string str);
	int Output();
};
int Student::Input(int a, string str)
{
	a = age;
	str = name;
	return 0;
}

int Student::Output()
{
	cout << age << " " << name << endl;
	return 0;
}
void main()
{
	int i;
	Student a[3];
	for (i = 0; i < 3; i++)
	{
		cout << "请输入学生年龄，姓名";
		cin >> a[i].age >> a[i].name;
		a[i].Input(a[i].age, a[i].name);
	}
	for (i = 0; i < 3; i++)
	{
		a[i].Output();
	}
}