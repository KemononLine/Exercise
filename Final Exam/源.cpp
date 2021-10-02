#include <iostream>
using namespace std;

enum Month
{
	Jan=1,Feb,Mar,Apr,May
};
class Date
{
	int year;
	Month month;
	int day;
public:
	Date(int y = 2015, int m = 9, int d = 1)
	{
		year = y;
		month = Month(m);
		day = d;
	}
	void print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
};

void main()
{
	Date oneday(2014, 7, 1);
	oneday.print();
}

