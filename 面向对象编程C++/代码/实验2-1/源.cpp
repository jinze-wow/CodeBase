#include <string>
#include <iostream>
using namespace std;
class student
{
public:
    student();
    ~student();
    void setValues(int n, string str, char c);
    void display();
private:
    int num; string name;
    char sex;
};
student::student() {}
student::~student() {}
void student::setValues(int n, string str, char c)
{
    num = n; name = str; sex = c;
}
void student::display()
{
    cout << num << " " << name << " " << sex << endl;
}
class postgraduent : public student
{
public:
    postgraduent();
    ~postgraduent();
    void setAdvisor(string str) { advisor = str; }
    string getAdvisor() { return advisor; }
private:
    string advisor;
};
postgraduent::postgraduent()
{
}
postgraduent::~postgraduent()
{
}
void main()
{
    postgraduent xq;
    xq.setValues(29, "Xiao Qiang", 'M');
        xq.setAdvisor("Prof. Su");
    xq.display();
    cout << "Advisor: " << xq.getAdvisor() << endl;
}