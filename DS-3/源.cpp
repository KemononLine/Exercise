#include <iostream>
#include "MyString.h"
#include <cstring>
using namespace std;

int main()
{
	char s[10000];
	char t[10000];
	char p[10000];
	cin >> s >> t>>p;
	GetNext(t);
	KMPpro(s, p,t);
	cout << s << endl;

	return 0;
}