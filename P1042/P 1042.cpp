#include <iostream>
#include <cmath>
using namespace std;
int a[62510];
int main()
{
	int i, w = 0, l = 0;
	char x;
	for (i = 0; cin >> x && x != 'E';i++)
	{
		if (x == 'W')
			a[i] = 1;
		else
			a[i] = -1;
	}
	for (i = 0; ; i++)
	{
		if (a[i] == 0)
		{
			cout << w << ':' << l << endl << endl;
			break;
		}
		if (a[i] == 1)
			w++;
		if (a[i] == -1)
			l++;
		if (abs(w - l) >= 2 && (w >= 11 || l >= 11))
		{
			cout << w << ':' << l << endl;
			w = 0, l = 0;
		}
	}
	w = 0, l = 0;
	for (i = 0;; i++)
	{
		if (a[i] == 0)
		{
			cout << w << ':' << l << endl;
			break;
		}
		if (a[i] == 1)
			w++;
		if (a[i] == -1)
			l++;
		if (abs(w - l) >= 2 && (w >= 21 || l >= 21))
		{
			cout << w << ':' << l << endl;
			w = 0, l = 0;
		}
	}
	return 0;
}