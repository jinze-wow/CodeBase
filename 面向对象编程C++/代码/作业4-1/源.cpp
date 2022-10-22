//定义一个车(vehicle)基类，具有MaxSpeed、Weight等成员变量，Run、Stop等成员函数，
//由此公有派生出自行车(bicycle)类、汽车(motorcar)类。自行车类有高度(height)等属性，
//汽车类有座位数(SeatNum)等属性。从bicycle和motorcar公有派生出摩托车(motorcycle)类，
//在继承过程中，注意把vehicle设置为虚基类。
#include<iostream>
using namespace std;
class vehicle
{
public:
	vehicle(float m, float w) :MaxSpeed(m), weight(w) {}
	virtual void Run()
	{
		cout << "已启动 " << endl ;
	}
	virtual void Stop()
	{
		cout << " 已停车" << endl;
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
		cout << "自行车已启动 " << "自行车高度是：" << Height<< endl ;
	}
	void Stop()
	{
		cout << " 自行车已停车" << endl;
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
		cout << "汽车已启动 " <<"座位的数量是：" <<SeatNum << endl ;
	}
	void Stop()
	{
		cout << " 汽车已停车" << endl;
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
		cout << "摩托车最快速度:" << MaxSpeed << endl; 
		cout << "摩托车重量是:" << weight << endl;
		cout << "摩托车高度是:" << Height << endl;
		cout << "摩托车座位数量是:" << SeatNum << endl;
	}
	void Stop()
	{
		cout << "摩托车已停车 " << endl;
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
