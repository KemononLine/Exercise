#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	char a[10001], b[10001];
	int aa[10001], bb[10001], cc[10001], i, j;
	cin >> a >> b;
	int lena = strlen(a);
	int lenb = strlen(b);
	for (i = 1;i <= lena;i++)
		aa[i] = a[lena - i] - '0';
	for (i = 1;i <= lenb;i++)
		bb[i] = a[lenb - i] - '0';
	for (i = 1;i <= lenb;i++)
		for (j = 1;j <= lena;j++)
			cc[i + j - 1] = aa[i] * bb[j];
	int len = lena + lenb;
	for (i = 1;i < len;i++)
	{
		if (cc[i] > 9)
		{
			cc[i + 1] = cc[i] / 10;
			cc[i] %= 10;
		}
	}
	while (cc[len] == 0 && len > 1)
		len--;
	for (i = len;i >= 1;i--)
		cout << cc[i];

	return 0;
}