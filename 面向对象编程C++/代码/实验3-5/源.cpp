
/*设计一个类people,有保护数据成员:age(年龄,整型)，name(姓名，string)，
行为成员：两个构造函数（一个默认，另一个带参数），析构函数；
void setValue(int m, string str)给age和name赋值；
有一个void类型的纯虚函数display()。
设计一个学生类student,公有继承类people,有私有成员：studentID(学号,整型)，
行为成员：两个构造函数（一个默认，另一个带参数）；
析构函数；void setID(int m)给studentID赋值；display()函数输出学生的姓名，年龄，学号。
设计一个教师类teacher,公有继承类people,有私有成员：teacherID(工号,整型)，
行为成员：两个构造函数（一个默认，另一个有参数）；
默认析构函数；void setID(int m)给teacherID赋值；
display()函数输出教师的姓名，年龄，工号。在main函数定义学生对象和教师对象，
给对象初始化赋值或调用setValue()和setID()赋值，并输出学生和老师的信息。
*/
//崔金泽 2021/5/8
//定义类
#include<iostream>
using namespace std;
class People {
protected:
    int age;//age(年龄,整型)
    string name;//name(姓名，string)
public:
    People() {};//默认构造函数
    People(int a, string n) {//有参数的构造函数
        age = a;
        name = n;
    }
    ~People() {};//析构函数
    void setValue(int m, string str) {
        age = m;
        name = str;
    }
    virtual void display() const = 0;//纯虚函数
};

void fun(People* ptr) {//定义抽象类的指针和引用
    ptr->display();
}

class Student : public People {//Student类公有继承People类
private:
    int studentID;//studentID(学号,整型)
public:
    Student() {};//默认构造
    Student(int age, string name, int studentID) :People(age, name) {//含参构造
        this->studentID = studentID;
    }
    ~Student() {};//析构
    void setID(int m) {//给studentID赋值
        this->studentID = m;
    }
    void display() const {//覆盖基类的虚函数，输出学生的姓名、年龄、学号
        cout << name << "," << age << "," << studentID << endl;
    }
};

class Teacher : public People {//Teacher类公有继承People类
private:
    int teacherID;//teacherID(工号,整型)
public:
    Teacher() {};//默认构造
    Teacher(int age, string name, int teacherID) :People(age, name) {//含参构造
        this->teacherID = teacherID;
    }
    ~Teacher() {};//析构函数
    void setID(int m) {//给teacherID赋值
        this->teacherID = m;
    }
    void display() const {//输出教师的姓名、年龄、工号
        cout << name << "," << age << "," << teacherID << endl;
    }
};



int main() {
    //定义对象
    People* people;
    Student student;
    Teacher teacher;
    int age;
    string name;
    int id;
    /*这里默认Student类和Teacher类的年龄、姓名相同*/
    cout << "请输入年龄age、姓名name" << endl;
    cin >> age >> name;
    people = &student;
    people->setValue(age, name);
    people = &teacher;
    people->setValue(age, name);
    cout << "请输入学号" << endl;
    cin >> id;
    student.setID(id);
    cout << "请输入工号" << endl;
    cin >> id;
    teacher.setID(id);
    fun(&student);
    fun(&teacher);
    return 0;
}