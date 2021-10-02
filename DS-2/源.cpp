#include <iostream>
#include "Mystack.h"
#include <cstring>
#include <stdlib.h>
using namespace std;
void menu();
double Exp();

int main()
{
	menu();
	int choice;
	double ans;
	cin >> choice;
	while (choice != 2)
	{
		switch (choice)
		{
		case 1:
			cout << "Please Input Expression" << endl;
			ans=Exp();
			cout << ans << endl;
			break;
		default:
			cerr << "Invalid Input" << endl;
			break;
		}
		menu();
		cin >> choice;
	}

	return 0;
}

void menu()
{
	cout << "Enter Numbers to Choose Function" << endl;
	cout << "1.Calutaor" << endl;
	cout << "2.Exit" << endl;
}

double Exp()
{
	LinkStack<char> OPTR;
	LinkStack<double> OPND;
	OPTR.Push('@');
	char ch = getchar();
	ch = getchar();
	int flag = 0;
	while (ch!='@'||OPTR.Top()!='@')
	{
		char temp[10000] = {'?'};
		for (int i = 0;ch >= '0' && ch <= '9' || ch == '.';i++)
		{
			temp[i] = ch;
			flag = 1;
			ch = getchar();
		}
		if (flag)
		{
			double ans = atof(temp);
			OPND.Push(ans);
		}
		flag = 0;
		char pre_op = OPTR.Top();
		switch (Precede(pre_op,ch))
		{
		case '<':
			OPTR.Push(ch);
			ch = getchar();
			break;
		case '=':
			OPTR.Pop();
			ch = getchar();
			break;
		case '>':
			double b = OPND.Pop();
			double a = OPND.Pop();
			pre_op = OPTR.Pop();
			OPND.Push(Operate(a, pre_op, b));
			break;
		}
	}
	return OPND.Top();
}