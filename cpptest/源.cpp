#include <iostream>
#include <string>
using namespace std;
/*
enum Month
{
	Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
};
class Date
{
	int year;
	Month month;
	int day;
public:
	Date(int y = 0, int m = 0, int d = 0) :year(y), month(Month(m)), day(d)
	{
		cout << "No.1 func" << endl;
	}
	Date(int d, Month m,int y) :year(y), month(m), day(d)
	{
		cout << "No.2 func" << endl;
	}
	Date(Month m, int d, int y) :year(y), month(m), day(d)
	{
		cout << "No.3 func" << endl;
	}
	~Date()
	{
		cout << "Destrcut func" << endl;
	}
	void init_date(int y, int m, int d)
	{
		year = y;
		month =Month(m);
		day = d;
	}
	void print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
};

void main()
{
	Date* pt1 = new Date(2016, 1, 1);
	pt1->print();
	Date* pt2 = (Date*) malloc(sizeof(Date));
	pt2->print();
	pt2->init_date(2017, 2, 3);
	pt2->print();
	delete pt1;
	free(pt2);
	Date oneday;
	oneday.print();
}
*/
