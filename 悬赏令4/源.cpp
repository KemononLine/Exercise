#include<iostream>
#include<algorithm>
using namespace std;
int A[100][100] = { 0 }, MAX[100][100] = { 0 };
int x, y;
int Max(int i, int j);

int Max(int i, int j)
{
	int ii, jj;
	int a[4] = { 0,0,1,-1 }, b[4] = { 1,-1,0,0 };
	if (MAX[i][j] != 0)
		return MAX[i][j];
	MAX[i][j] = 1;
	for (int t = 0; t < 4; t++)
	{
		ii = i + a[t];
		jj = j + b[t];
		if (ii >= 1 && jj >= 1 && ii <= x && jj <= y && A[ii][jj] < A[i][j])
		{
			Max(ii, jj);
			MAX[i][j] = max(MAX[i][j], MAX[ii][jj] + 1);
		}
	}
	return MAX[i][j];
}

int main()
{
	int i, j, t = 0, ans = 0;
	cin >> x >> y;
	for (i = 1; i<=x; i++)
		for (j = 1; j<=y; j++)
			cin >> A[i][j];
	for (i = 1; i<=x; i++)
		for (j = 1; j<=y; j++)
			ans = max(Max(i, j), ans);
	cout << ans << endl;
	return 0;
}
