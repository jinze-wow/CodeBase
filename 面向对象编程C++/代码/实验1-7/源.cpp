//���ڸ����ࣨ��ʦ���ӻ���ҵ�������帴�����һ����Ԫ����
//complex add(complex x,complex y)��
//����������������ļӷ������ڼ������������˷����ơ�
//�޽��� 2021/4/10
#include <iostream>
#include<math.h>
using namespace std;
class complex
{
public:
	complex(); //�޲ι��캯��
	complex(complex& c); //��ȸ��ƹ��캯��
	complex(double r, double i); //��ͨ���캯��
	friend void input_complex(complex& comp);
	friend complex add(complex& b, complex& c); //���
	friend complex sub(complex& b, complex& c); //���
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
complex::complex(double r, double i)//ͬʱ��ʵ���鲿��ֵ�ĺ���
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
	cout << "�����:" << comp.real << (comp.imag > 0 ? "+" : "-") << abs(comp.imag) << "i" << endl; //abs()ȡ����ֵ����
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
	cout << "�������һ��������ʵ�����鲿��" << endl;
	input_complex(c1);
	cout << "������ڶ���������ʵ�����鲿��" << endl;
	input_complex(c2);
	result = add(c1, c2);//���ø�ֵ���캯��
	output_complex(result);
	result = sub(c1, c2);
	output_complex(result);
	result = mul(c1, c2);
	output_complex(result);
}