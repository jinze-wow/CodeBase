/*ѧ�������������༶��ѧ�ŵ����ԣ����Ͽε���Ϊ����ʦ���й��ţ�
���ʵ����ԣ��н̿ε���Ϊ�����̼���ѧ����������ʦ��
����ѧ������ʦ��˫�����ԡ�������Ķ�̳л���ʵ���������⡣*/
//�޽��� 2021/4/10
#include<iostream>
#include<string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Student
{
public:
	Student() {};
	Student(string x, int y, int z) {//�в����Ĺ��캯��
		name = x;
		grad = y;
		StuNo = z;
	}
	void Print()
	{
		cout << "����: " << name << endl;
		cout << "�༶: " << grad << endl;
		cout << "ѧ��: " << StuNo << endl;
	}
	void classing()
	{
		cout << "�Ͽ�" << endl;
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
		cout << "����: " << TecNo << endl;
		cout << "����: " << Pay << endl;
	}
	void teaching()
	{
		cout << "�ڿ�" << endl;
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
	cout << "������ѧ�����������༶��ѧ��" << endl;
	cin >> x >> y >> z ;
	Student stu(x,y,z);
	stu.Print();
	stu.classing();
	cout << "��������ʦ�����������ź͹���" << endl;
	cin >> q >> w >> e;
	Teacher tea(q,w,e);
	tea.Print();
	tea.teaching();
	cout << "���������̵ĵ��������༶��ѧ�ţ����ź͹���" << endl;
	cin >> x >> y >> z >> w >> e;
	Assistant assistant1(x,y,z,w,e);
	assistant1.Print();
	assistant1.classing();
	assistant1.teaching();
}


/*int main()
{
	string x, q; int y, z, w, e;
	cout << "������ѧ�����������༶��ѧ��" << endl;
	cin >> x >> y >> z;
	cout << "����: " << x << endl;
	cout << "�༶: " << y << endl;
	cout << "ѧ��: " << z << endl;
	cout << "��������ʦ�����������ź͹���" << endl;
	cin >> q >> w >> e;
	cout << "����: " << q << endl;
	cout << "����: " << w << endl;
	cout << "����: " << e << endl;
	cout << "�ڿ�" << endl;
	cout << "���������̵ĵ��������༶��ѧ�ţ����ź͹���" << endl;
	cin >> x >> y >> z >> w >> e;
	cout << "����: " << x << endl;
	cout << "�༶: " << y << endl;
	cout << "ѧ��: " << z << endl;
	cout << "����: " << w << endl;
	cout << "����: " << e << endl;
	cout << "�ڿ�" << endl;
}*/