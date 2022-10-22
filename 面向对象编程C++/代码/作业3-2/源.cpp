//定义一个大学生类student，含私有数据成员：姓名、学号、校名；
//公有成员：带参数的构造函数和能输出学生信息的成员函数。
//另定义研究生类，它以公有继承方式派生于类student，
//新增加“研究方向、导师名”两个私有数据成员；公有成员：
//带参数的构造函数和能输出研究生信息的成员函数。
//在main()中定义基类和派生类对象，分别调用两个信息输出函数进行测试。
#include <iostream>
using namespace std;
class student
{
private:
	string name;
	int num;
	string school;
public:
	student(){}
	student(string na, int nu, string sc);
	void output();
	void setstudent(string na, int nu, string sc)
	{
		name = na;
		num= nu;
		school = sc;
	}
};
void student::output()
{
	cout <<"姓名:" <<name << "学号:" << num << "学校:" << school ;
}
student::student(string na, int nu, string sc)
{
	name = na;
	num = nu; 
	school = sc;
}

class master :public student
{
private:
	string direction;
	string teacher;
public:
	master(){}
	master(string na, int nu, string sc, string d, string t)
	{
		student::setstudent(na, nu, sc);
		direction = d;
		teacher = t;
	}

 void output()
	{
		student::output();
		cout << "研究方向: " << direction<< "指导老师: "<< teacher ;
	}

};


int main()
{
	student m("A", 20191111, "铁道大学");
	m.output();
	cout << endl;
	master n("B", 20181111,"铁道大学", "计算机", "周老师");
	n.output();
}