#include <iostream>
using namespace std;
struct Toy
{
	int dir=0;
	string pro="NoName";
};
Toy a[100010];
int n, m, ai, si;
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i].dir >> a[i].pro;
	}
	int cur = 0;
	for (int i = 1;i <= m;i++)
	{
		cin >> ai >> si;
		if (a[cur].dir^ai)
			cur = (cur + si) % n;
		else
			cur = (cur + n - si) % n;

	}
	cout << a[cur].pro;

	return 0;
}
