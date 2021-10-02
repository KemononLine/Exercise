#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;
char s[12];
char s1[20];
const int MAX = 5;
class MyString
{
public:
	char* str;
	int length;
	static void Menu()
	{

	}
	MyString(char* s)
	{
		cout << "Constructing!" << endl;
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		length = 1;
	}
	~MyString()
	{
		cout << "Destructing!" << endl;
		delete[]str;
	}
	void Copy(char* s)
	{
		char* x;
		x = new char[strlen(s) - 1];
		strcpy(x, s);
		delete[]str;
		str = x;
		length = strlen(x);
		cout << str << endl;
	}
	void Concatenate(char* z)
	{
		char* a;
		a = new char[strlen(z) + length];
		strcpy(a, str);
		strcat(a, z);
		str = a;
		cout << str << endl;
	}
	void Compare(char* b)
	{
		cout << "compare result is:" << strcmp(str, b) << endl;
	}
	void Swap(char* e)
	{
		char* temp1, * temp2;
		temp1 = new char[length];
		temp2 = new char[strlen(e) + 1];
		strcpy(temp1, str);
		strcpy(temp2, e);
		str = temp2;
		e = temp1;
		cout << e << "\n" << str << endl;
	}
	char *Substring(int start,int end)
	{
		char* nstr = new char[end - start + 1];
		int i, j = 0;
		for (i = start;i < end;i++)
		{
			nstr[j] = str[i];
		}
		nstr[j] = '\0';
		return nstr;
	}
};
void Write(char s1[10])
{
	ofstream out;
	out.open("D:\NNUCS\MyProjects\19200213李铖彧3\data.txt", ios::out | ios::ate | ios::app);
	if (!out)
	{
		cout << "Error" << endl;
		exit(0);
	}
	out << s1 << '\n';
	out.close();
}
void Write2(int n)
{
	ofstream out;
	out.open("D:\NNUCS\MyProjects\19200213李铖彧3\data.txt", ios::out | ios::ate | ios::app);
	if (!out)
	{
		cout << "Error" << endl;
		exit(0);
	}
	while (n)
	{
		char s1[20];
		cin >> s1;
		out << s1 << '\n';
		n--;
	}
	out.close();
}
char* Read()
{
	ifstream in;
	in.open("D:\NNUCS\MyProjects\19200213李铖彧3\data.txt", ios::in);
	if (!in)
	{
		cout << "Error" << endl;
		exit(0);
	}
	int k = 1;
	while (k)
	{
		in.getline(s, 12);
		k = 0;
	}
	in.close();
	return s;
}
char* Read2(int k)
{
	ifstream in;
	in.open("D:\NNUCS\MyProjects\19200213李铖彧3\data.txt", ios::in);
	if (!in)
	{
		cout << "Error" << endl;
		exit(0);
		while (k)
		{
			in.getline(s, 12);
			k--;
		}
		in.close();
		return s;
	}
}