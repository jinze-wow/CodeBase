//崔金泽 2021/4/10
#include <iostream>
using namespace std;

class Base
{
public:
    Base(int nId) { mId = nId; }
    int GetId() { mId++; cout << mId << endl; return mId; }
protected:
    int GetNum() { cout << 0 << endl; return 0; }
private:
    int mId;
};

class Child : protected Base
{
public:
    Child() : Base(7) { ; }
    int GetCId() { return GetId(); }   //可以访问基类的公有成员和保护成员
    int GetCNum() { return GetNum(); }
protected:
    int y;
private:
    int x;
};

int main()
{
    Child child;
    //child.GetId();//派生类对象访问不了继承的公有成员
    //child.GetNum(); //无法访问
    child.GetCId();
    child.GetCNum();
    return 0;
}

