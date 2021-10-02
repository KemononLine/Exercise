#include <iostream>
using namespace std;

int k = 0;
int a[1000][1000] = { 0 };
int sxpt, sypt, n, m, t, fxpt, fypt;
int DFS(int x, int y);
void Input(int n);

int DFS(int x, int y)
{
	if (a[x][y] == 1)
		return 0;
	if (x > m || y > n || x < 1 || y < 1)
	{
		a[x][y] = 1;
		return 0;
	}
	if (x == fxpt && y == fypt)
	{
		k++;
		return 0;
	}
	a[x][y] = 1;
	DFS(x + 1, y);
	DFS(x, y + 1);
	DFS(x - 1, y);
	DFS(x, y - 1);
	return 0;
}

void Input(int n)
{
	int x, y;
	for (int i = 0; n > i; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
	}
}

int main()
{
	cin >> n >> m >> t;
	cin >> sxpt >> sypt >> fxpt >> fypt;
	Input(t);
	DFS(sxpt, sypt);
	cout << k << endl;
	return 0;
}
