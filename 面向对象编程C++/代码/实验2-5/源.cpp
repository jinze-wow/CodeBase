//�޽��� 2021/4/10
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
    int GetCId() { return GetId(); }   //���Է��ʻ���Ĺ��г�Ա�ͱ�����Ա
    int GetCNum() { return GetNum(); }
protected:
    int y;
private:
    int x;
};

int main()
{
    Child child;
    //child.GetId();//�����������ʲ��˼̳еĹ��г�Ա
    //child.GetNum(); //�޷�����
    child.GetCId();
    child.GetCNum();
    return 0;
}

