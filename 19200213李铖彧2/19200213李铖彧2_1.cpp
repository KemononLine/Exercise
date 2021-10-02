#include <iostream>
using namespace std;
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time()
	{}
	void init_time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	void print()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	void Add()
	{
		if (second == 59)
		{
			if (minute == 59)
				hour++;
			else
			{
				minute ++;
			}
		}
		else
			second++;
	}
	Time( Time& now) :hour(now.hour), minute(now.minute), second(now.second) {}
	~Time()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
};

void fun(Time now)
{
	now.Add();
}
void main()
{
	Time now;
	now.init_time(23, 34, 12);
	fun(now);
	return;
}