/*定义猫科动物Animal类，由其派生出猫类（Cat）和豹类（Leopard）
1.每个类都有各自的构造函数（2个）和析构函数；
2.	Animal类中定义虚函数void speak()，显示“My name is Animal.”，
在派生类中分别重新定义该函数，显示“My name is  **”，其中**由各自类名决定；
3.	在主函数中分别定义三个类的对象和基类指针，
通过指针完成对子类speak函数的调用。
思考：若要求在基类中将speak声明为纯虚函数，程序该如何修改？
是否还能定义Animal类的对象？
*/
//崔金泽 2021/5/8
#include<iostream>
using namespace std;
class Animal
{
public:
	int a, b;

	
	//虚函数
	virtual void speak()
	{
		cout << "My name is Animal." << endl;
	}
	
};

//猫类
class Cat : public Animal
{
public:

	
	//函数重写：函数返回值、函数名、函数的参数列表完全相同
	void speak()
	{
		cout << "My name is " <<"cat"<< endl;
	}
	
};

//豹类
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