//����һ����(vehicle)���࣬����MaxSpeed��Weight�ȳ�Ա������Run��Stop�ȳ�Ա������
//�ɴ˹������������г�(bicycle)�ࡢ����(motorcar)�ࡣ���г����и߶�(height)�����ԣ�
//����������λ��(SeatNum)�����ԡ���bicycle��motorcar����������Ħ�г�(motorcycle)�࣬
//�ڼ̳й����У�ע���vehicle����Ϊ����ࡣ
#include<iostream>
using namespace std;
class vehicle
{
public:
	vehicle(float m, float w) :MaxSpeed(m), weight(w) {}
	virtual void Run()
	{
		cout << "������ " << endl ;
	}
	virtual void Stop()
	{
		cout << " ��ͣ��" << endl;
	}

protected:
	float MaxSpeed;
	float weight;
};
class bicycle :virtual public vehicle
{
public:
	bicycle(float m, float w, float h) :vehicle(m, w), Height(h) {}
	void Run()
	{
		cout << "���г������� " << "���г��߶��ǣ�" << Height<< endl ;
	}
	void Stop()
	{
		cout << " ���г���ͣ��" << endl;
	}
protected:
	float Height;
};
class motorcar : virtual public vehicle
{
public:
	motorcar(float m, float w, float s) :vehicle(m, w), SeatNum(s) {}
	void Run()
	{
		cout << "���������� " <<"��λ�������ǣ�" <<SeatNum << endl ;
	}
	void Stop()
	{
		cout << " ������ͣ��" << endl;
	}
protected:
	int SeatNum;
};
class motorcycle : public bicycle, public motorcar
{
public:
	motorcycle(float m, float w, float h, float s) :vehicle(m, w), bicycle(m, w, h), motorcar(m, w, s) {}
	void Run()
	{
		cout << "Ħ�г�����ٶ�:" << MaxSpeed << endl; 
		cout << "Ħ�г�������:" << weight << endl;
		cout << "Ħ�г��߶���:" << Height << endl;
		cout << "Ħ�г���λ������:" << SeatNum << endl;
	}
	void Stop()
	{
		cout << "Ħ�г���ͣ�� " << endl;
	}

};
int main() {
	vehicle a(108, 53);
	bicycle b(180, 50, 1.2);
	motorcar c(180, 80, 5);
	motorcycle d(120, 90,1.2,3);
	vehicle* p[4] = { &a,&b,&c,&d };
	for (int i = 0; i < 4; i++)
	{
		p[i]->Run();
		p[i]->Stop();
	}
	return 0;
}
