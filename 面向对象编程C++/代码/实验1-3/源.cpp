//����һ��ѧ���࣬���˽�����ݳ�Ա������ int age;���� string name;���г�Ա������
//�������ĳ�ʼ������  Input(int a, string str);��ȡ���ݳ�Ա����    
//Output();���������ж���һ����3��Ԫ�صĶ������鲢�ֱ����룬Ȼ����������������Ϣ��
//�޽��� 2021/4/10
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
		cout << "������ѧ�����䣬����";
		cin >> a[i].age >> a[i].name;
		a[i].Input(a[i].age, a[i].name);
	}
	for (i = 0; i < 3; i++)
	{
		a[i].Output();
	}
}