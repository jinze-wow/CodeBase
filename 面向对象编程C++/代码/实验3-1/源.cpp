#include <iostream>
using namespace std;
class Complex
{
public:
    Complex(double real = 0.0, double image = 0.0)
    {
        this->real = real, this->image = image;
    }
    ~Complex(void);
    void display();
    Complex operator + (Complex B);
private:
    double real;
    double image;
};
Complex::~Complex(void) {}
void Complex::display() {
    cout << real;
    if (image > 0)
        cout << " + ";
    cout << image << "i";
}
Complex Complex::operator +(Complex B) {
    return Complex(this->real + B.real, this->image + B.image);
}

void main()
{
    Complex A(1.0, 2.0), B(3.0, 4.0), C;
    cout << "Complex A: ";
    A.display();
    cout << endl;
    cout << "Complex B: ";
    B.display();
    cout << endl;
    C = A + B; cout << "Complex A + B: ";
    C.display();
    cout << endl;
}

