#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, Ta, Tb, a[201], b[201];
    cin >> n >> Ta >> Tb;
    for (int i = 1;i <= Ta;i++)
        cin >> a[i];
    for (int j = 1;j <= Tb;j++)
        cin >> b[j];
    int ans = 0;
    int bns = 0;
    int i = 0;
    int j = 0;
    for (int k = 1;k <= n;k++)
    {
        i++;
        j++;
        if (i > Ta) i = 1;
        if (j > Tb) j = 1;
        if (a[i] == 0 && b[j] == 1)bns++;
        if (a[i] == 0 && b[j] == 2)ans++;
        if (a[i] == 0 && b[j] == 3)ans++;
        if (a[i] == 0 && b[j] == 4)bns++;
        if (a[i] == 1 && b[j] == 0)ans++;
        if (a[i] == 1 && b[j] == 2)bns++;
        if (a[i] == 1 && b[j] == 3)ans++;
        if (a[i] == 1 && b[j] == 4)bns++;
        if (a[i] == 2 && b[j] == 0)bns++;
        if (a[i] == 2 && b[j] == 1)ans++;
        if (a[i] == 2 && b[j] == 3)bns++;
        if (a[i] == 2 && b[j] == 4)ans++;
        if (a[i] == 3 && b[j] == 0)bns++;
        if (a[i] == 3 && b[j] == 1)bns++;
        if (a[i] == 3 && b[j] == 2)ans++;
        if (a[i] == 3 && b[j] == 4)ans++;
        if (a[i] == 4 && b[j] == 0)ans++;
        if (a[i] == 4 && b[j] == 1)ans++;
        if (a[i] == 4 && b[j] == 2)bns++;
        if (a[i] == 4 && b[j] == 3)bns++;
    }
    cout << ans << " " << bns;
    return 0;
}