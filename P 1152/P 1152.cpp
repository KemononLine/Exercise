#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
bool a[100000005];

int main()
{
	int n;
	int now, last = 0;
	scanf_s("%d", &n);
	for (int i = 1;i <= n;++i)
	{
		scanf_s("%d", &now);
		a[abs(now - last)] = true;
		last = now;
	}
	for (int i = 1;i < n;++i)
	{
		if (a[i] != true)
		{
			cout << "Not jolly" << endl;
			return 0;
		}
	}
	cout << "Jolly" << endl;
	return 0;
}