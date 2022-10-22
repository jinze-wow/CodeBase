//设计一个类people, 有保护数据成员:age(年龄, 整型)，name(姓名，string)，
//行为成员：两个构造函数（一个默认，另一个带参数）；析构函数；void setValue(int m, string str)
//给age和name赋值；有一个void类型的纯虚函数display()。
//设计一个学生类student, 公有继承类people, 有私有成员：studentID(学号, 整型)，
//行为成员：两个构造函数（一个默认，另一个带参数）；析构函数；void setID(int m)给studentID赋值；
//display()函数输出学生的姓名，年龄，学号。
//设计一个教师类teacher,公有继承类people,有私有成员：teacherID(工号,整型)，行为成员：
//两个构造函数（一个默认，另一个有参数）；默认析构函数；void setID(int m)给teacherID赋值； 
//display()函数输出教师的姓名，年龄，工号。在main函数定义学生对象和教师对象，
//给对象初始化赋值或调用setValue()和setID()赋值，并输出学生和老师的信息。
//崔金泽 2021/4/10
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
    cout << "请输入学生和老师的姓名，年龄和学号" << endl;
    cin >> x >> y >> z >> q >> w >> e;
    Student st(x, y, z);
    Teacher te(q, w, e);

    cout << "修改前" << endl;
    st.display();
    te.display();

    // 修改ID 
    cout << "请输入学生和老师修改后的id" << endl;
    cin >> z2 >> e2;
    st.setID(z2);
    te.setID(e2);

    cout << "\n修改后" << endl;
    st.display();
    te.display();
    return 0;
}