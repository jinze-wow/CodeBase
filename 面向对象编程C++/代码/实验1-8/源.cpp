#include <iostream>
using namespace std;
class Time;
class Date
{
public:
	Date(int, int, int);
	void display(Time&);
private:
	int year, month, day;
};
class Time
{
public:
	Time(int, int, int);
	friend Date;
private:
	int hour, minu, sec;
};
Time::Time(int h, int m, int s)
{
	hour = h;	minu = m;	sec = s;
}
Date::Date(int y, int m, int d)
{
	year = y;	month = m; day = d;
}
void Date::display(Time& t)
{
	cout << year << "/" << month << "/" << day << endl;
	cout << t.hour << ":" << t.minu << ":" << t.sec;
}
void main()
{
	Date d1(2014, 2, 5);
	Time t1(11, 1, 1);
	d1.display(t1);

}
