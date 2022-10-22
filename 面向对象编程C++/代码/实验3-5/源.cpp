
/*���һ����people,�б������ݳ�Ա:age(����,����)��name(������string)��
��Ϊ��Ա���������캯����һ��Ĭ�ϣ���һ����������������������
void setValue(int m, string str)��age��name��ֵ��
��һ��void���͵Ĵ��麯��display()��
���һ��ѧ����student,���м̳���people,��˽�г�Ա��studentID(ѧ��,����)��
��Ϊ��Ա���������캯����һ��Ĭ�ϣ���һ������������
����������void setID(int m)��studentID��ֵ��display()�������ѧ�������������䣬ѧ�š�
���һ����ʦ��teacher,���м̳���people,��˽�г�Ա��teacherID(����,����)��
��Ϊ��Ա���������캯����һ��Ĭ�ϣ���һ���в�������
Ĭ������������void setID(int m)��teacherID��ֵ��
display()���������ʦ�����������䣬���š���main��������ѧ������ͽ�ʦ����
�������ʼ����ֵ�����setValue()��setID()��ֵ�������ѧ������ʦ����Ϣ��
*/
//�޽��� 2021/5/8
//������
#include<iostream>
using namespace std;
class People {
protected:
    int age;//age(����,����)
    string name;//name(������string)
public:
    People() {};//Ĭ�Ϲ��캯��
    People(int a, string n) {//�в����Ĺ��캯��
        age = a;
        name = n;
    }
    ~People() {};//��������
    void setValue(int m, string str) {
        age = m;
        name = str;
    }
    virtual void display() const = 0;//���麯��
};

void fun(People* ptr) {//����������ָ�������
    ptr->display();
}

class Student : public People {//Student�๫�м̳�People��
private:
    int studentID;//studentID(ѧ��,����)
public:
    Student() {};//Ĭ�Ϲ���
    Student(int age, string name, int studentID) :People(age, name) {//���ι���
        this->studentID = studentID;
    }
    ~Student() {};//����
    void setID(int m) {//��studentID��ֵ
        this->studentID = m;
    }
    void display() const {//���ǻ�����麯�������ѧ�������������䡢ѧ��
        cout << name << "," << age << "," << studentID << endl;
    }
};

class Teacher : public People {//Teacher�๫�м̳�People��
private:
    int teacherID;//teacherID(����,����)
public:
    Teacher() {};//Ĭ�Ϲ���
    Teacher(int age, string name, int teacherID) :People(age, name) {//���ι���
        this->teacherID = teacherID;
    }
    ~Teacher() {};//��������
    void setID(int m) {//��teacherID��ֵ
        this->teacherID = m;
    }
    void display() const {//�����ʦ�����������䡢����
        cout << name << "," << age << "," << teacherID << endl;
    }
};



int main() {
    //�������
    People* people;
    Student student;
    Teacher teacher;
    int age;
    string name;
    int id;
    /*����Ĭ��Student���Teacher������䡢������ͬ*/
    cout << "����������age������name" << endl;
    cin >> age >> name;
    people = &student;
    people->setValue(age, name);
    people = &teacher;
    people->setValue(age, name);
    cout << "������ѧ��" << endl;
    cin >> id;
    student.setID(id);
    cout << "�����빤��" << endl;
    cin >> id;
    teacher.setID(id);
    fun(&student);
    fun(&teacher);
    return 0;
}