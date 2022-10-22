/*学生具有姓名，班级，学号等属性，有上课等行为；教师具有工号，
工资等属性，有教课等行为；助教既是学生，又是老师，
具有学生和老师的双重属性。请用类的多继承机制实现上述问题。*/
//崔金泽 2021/4/10
#include<iostream>
#include<string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Student
{
public:
	Student() {};
	Student(string x, int y, int z) {//有参数的构造函数
		name = x;
		grad = y;
		StuNo = z;
	}
	void Print()
	{
		cout << "姓名: " << name << endl;
		cout << "班级: " << grad << endl;
		cout << "学号: " << StuNo << endl;
	}
	void classing()
	{
		cout << "上课" << endl;
	}
protected:
	string name;
	int grad;
	int StuNo;
};
class Teacher
{
public:
	Teacher() {};
	Teacher(string q, int w, int e){
		na = q;
		TecNo = w;
		Pay = e;
	}

	void Print()
	{
		cout << "工号: " << TecNo << endl;
		cout << "工资: " << Pay << endl;
	}
	void teaching()
	{
		cout << "授课" << endl;
	}
protected:
	string TecNo;
	string Pay;
};

class Assistant :public Student, public Teacher
{
public:
	Assistant(string na, int grad, int StuNo, int TecNo, int Pay) :Student( na,  grad, StuNo), Teacher(na,TecNo,  Pay)
	{
	}
	void Print()
	{
		Student::Print();
		Teacher::Print();
	}
};
int main()
{
	string x, q; int y, z, w, e;
	cout << "请输入学生的姓名，班级和学号" << endl;
	cin >> x >> y >> z ;
	Student stu(x,y,z);
	stu.Print();
	stu.classing();
	cout << "请输入老师的姓名，工号和工资" << endl;
	cin >> q >> w >> e;
	Teacher tea(q,w,e);
	tea.Print();
	tea.teaching();
	cout << "请输入助教的的姓名，班级和学号，工号和工资" << endl;
	cin >> x >> y >> z >> w >> e;
	Assistant assistant1(x,y,z,w,e);
	assistant1.Print();
	assistant1.classing();
	assistant1.teaching();
}


/*int main()
{
	string x, q; int y, z, w, e;
	cout << "请输入学生的姓名，班级和学号" << endl;
	cin >> x >> y >> z;
	cout << "姓名: " << x << endl;
	cout << "班级: " << y << endl;
	cout << "学号: " << z << endl;
	cout << "请输入老师的姓名，工号和工资" << endl;
	cin >> q >> w >> e;
	cout << "姓名: " << q << endl;
	cout << "工号: " << w << endl;
	cout << "工资: " << e << endl;
	cout << "授课" << endl;
	cout << "请输入助教的的姓名，班级和学号，工号和工资" << endl;
	cin >> x >> y >> z >> w >> e;
	cout << "姓名: " << x << endl;
	cout << "班级: " << y << endl;
	cout << "学号: " << z << endl;
	cout << "工号: " << w << endl;
	cout << "工资: " << e << endl;
	cout << "授课" << endl;
}*/