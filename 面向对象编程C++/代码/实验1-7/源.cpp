//对于复数类（老师例子或作业），定义复数类的一个友元函数
//complex add(complex x,complex y)，
//用于完成两个复数的加法，对于减法、除法、乘法类似。
//崔金泽 2021/4/10
#include <iostream>
#include<math.h>
using namespace std;
class complex
{
public:
	complex(); //无参构造函数
	complex(complex& c); //深度复制构造函数
	complex(double r, double i); //普通构造函数
	friend void input_complex(complex& comp);
	friend complex add(complex& b, complex& c); //相加
	friend complex sub(complex& b, complex& c); //相减
	friend complex mul(complex& b, complex& c);
	friend void output_complex(complex& comp);
private:
	double real;
	double imag;
};
void input_complex(complex& comp)
{
	cin >> comp.real >> comp.imag;
}
complex::complex()
{
	real = 0;
	imag = 0;
}
complex::complex(double r, double i)//同时给实、虚部赋值的函数
{
	real = r;
	imag = i;
}
complex::complex(complex& c)
{
	real = c.real;
	imag = c.imag;
}

void output_complex(complex& comp)
{
	cout << "结果是:" << comp.real << (comp.imag > 0 ? "+" : "-") << abs(comp.imag) << "i" << endl; //abs()取绝对值函数
}
complex add(complex& b, complex& c)
{
	complex x;
	x.real = b.real + c.real;
	x.imag = b.imag + c.imag;
	return x;
}
complex sub(complex& b, complex& c)
{
	complex x;
	x.real = b.real - c.real;
	x.imag = b.imag - c.imag;
	return x;
}
complex mul(complex& b, complex& c)
{
	complex x;
	x.real = b.real * c.real - b.imag * c.imag;
	x.imag = b.real * c.imag + b.imag * c.real;
	return x;
}
int main()
{
	complex c1, c2, result;
	cout << "请输入第一个复数的实部和虚部：" << endl;
	input_complex(c1);
	cout << "请输入第二个复数的实部和虚部：" << endl;
	input_complex(c2);
	result = add(c1, c2);//调用赋值构造函数
	output_complex(result);
	result = sub(c1, c2);
	output_complex(result);
	result = mul(c1, c2);
	output_complex(result);
}