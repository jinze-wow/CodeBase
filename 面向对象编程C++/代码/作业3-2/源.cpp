//����һ����ѧ����student����˽�����ݳ�Ա��������ѧ�š�У����
//���г�Ա���������Ĺ��캯���������ѧ����Ϣ�ĳ�Ա������
//�����о����࣬���Թ��м̳з�ʽ��������student��
//�����ӡ��о����򡢵�ʦ��������˽�����ݳ�Ա�����г�Ա��
//�������Ĺ��캯����������о�����Ϣ�ĳ�Ա������
//��main()�ж���������������󣬷ֱ����������Ϣ����������в��ԡ�
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
	cout <<"����:" <<name << "ѧ��:" << num << "ѧУ:" << school ;
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
		cout << "�о�����: " << direction<< "ָ����ʦ: "<< teacher ;
	}

};


int main()
{
	student m("A", 20191111, "������ѧ");
	m.output();
	cout << endl;
	master n("B", 20181111,"������ѧ", "�����", "����ʦ");
	n.output();
}