/*����è�ƶ���Animal�࣬����������è�ࣨCat���ͱ��ࣨLeopard��
1.ÿ���඼�и��ԵĹ��캯����2����������������
2.	Animal���ж����麯��void speak()����ʾ��My name is Animal.����
���������зֱ����¶���ú�������ʾ��My name is  **��������**�ɸ�������������
3.	���������зֱ���������Ķ���ͻ���ָ�룬
ͨ��ָ����ɶ�����speak�����ĵ��á�
˼������Ҫ���ڻ����н�speak����Ϊ���麯�������������޸ģ�
�Ƿ��ܶ���Animal��Ķ���
*/
//�޽��� 2021/5/8
#include<iostream>
using namespace std;
class Animal
{
public:
	int a, b;

	
	//�麯��
	virtual void speak()
	{
		cout << "My name is Animal." << endl;
	}
	
};

//è��
class Cat : public Animal
{
public:

	
	//������д����������ֵ���������������Ĳ����б���ȫ��ͬ
	void speak()
	{
		cout << "My name is " <<"cat"<< endl;
	}
	
};

//����
class Leopard : public Animal
{
public:
	
	
	void speak()
	{
		cout << "My name is " << "Leopard" << endl;
	}
	
};


int main()
{
	Animal* a;
	Cat c1;
	a = &c1;
	a->speak();
	Leopard l;
	a = &l;
	a->speak();
	return 0;
}