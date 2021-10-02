/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, m,width,length;
	cin >> n >> m;
	width = min(n, m);
	length = max(n, m);
	int sums = 0;
	for (int i = 0;i < width;i++)
	{
		sums += (n - i) * (m - i);
	}
	int sumr = 0;
	for (int i = 0;i < length;i++)
		for (int j = 0;j < width;j++)
			sumr += (length - i) * (width - j);
	sumr -= sums;
	cout << sums << " " << sumr;

}
*/
#include<iostream>
using namespace std;
long long n, m, sumrec, sumsqr;
int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
		{
			if (i == j)
				sumsqr += (n - i) * (m - j);
			else 
				sumrec += (n - i) * (m - j);
		}
	cout << sumsqr << " " << sumrec << endl;
	return 0;
}
