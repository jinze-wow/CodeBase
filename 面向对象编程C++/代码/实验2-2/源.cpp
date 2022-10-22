//���һ����people, �б������ݳ�Ա:age(����, ����)��name(������string)��
//��Ϊ��Ա���������캯����һ��Ĭ�ϣ���һ����������������������void setValue(int m, string str)
//��age��name��ֵ����һ��void���͵Ĵ��麯��display()��
//���һ��ѧ����student, ���м̳���people, ��˽�г�Ա��studentID(ѧ��, ����)��
//��Ϊ��Ա���������캯����һ��Ĭ�ϣ���һ����������������������void setID(int m)��studentID��ֵ��
//display()�������ѧ�������������䣬ѧ�š�
//���һ����ʦ��teacher,���м̳���people,��˽�г�Ա��teacherID(����,����)����Ϊ��Ա��
//�������캯����һ��Ĭ�ϣ���һ���в�������Ĭ������������void setID(int m)��teacherID��ֵ�� 
//display()���������ʦ�����������䣬���š���main��������ѧ������ͽ�ʦ����
//�������ʼ����ֵ�����setValue()��setID()��ֵ�������ѧ������ʦ����Ϣ��
//�޽��� 2021/4/10
#include<iostream>
#include<string>
using namespace std;

class People
{
protected:
    int age;
    string name;
public:
    People() {}
    ~People() {}
    People(string na, int ag)
    {
        age = ag;
        name = na;
    }

    void setValue(int m, string str)
    {
        age = m;
        name = str;
    }

    virtual void display() = 0;
};

class Student : public People
{
private:
    int studentID;
public:
    Student() {}
    ~Student() {}
    Student(string na, int ag, int sID) :
        People(na, ag)
    {
        studentID = sID;
    }

    void setID(int m)
    {
        studentID = m;
    }

    void display()
    {
        cout << name << " ";
        cout << age << " ";
        cout << studentID << endl;
    }
};

class Teacher : public People
{
private:
    int teacherID;

public:
    Teacher() {}
    ~Teacher() {}
    Teacher(string na, int ag, int tID) :
        People(na, ag)
    {
        teacherID = tID;
    }

    void setID(int m)
    {
        teacherID = m;
    }

    void display()
    {
        cout << name << " ";
        cout << age << " ";
        cout << teacherID << endl;
    }
};

int main()
{
    string x, q; int y, z, w, e, z2, e2;
    cout << "������ѧ������ʦ�������������ѧ��" << endl;
    cin >> x >> y >> z >> q >> w >> e;
    Student st(x, y, z);
    Teacher te(q, w, e);

    cout << "�޸�ǰ" << endl;
    st.display();
    te.display();

    // �޸�ID 
    cout << "������ѧ������ʦ�޸ĺ��id" << endl;
    cin >> z2 >> e2;
    st.setID(z2);
    te.setID(e2);

    cout << "\n�޸ĺ�" << endl;
    st.display();
    te.display();
    return 0;
}