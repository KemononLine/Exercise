/*
#include<iostream>
#include<cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

int A[10010][10010];
char str[1010];
int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        cin>>str;
        for (int j = 0;j < n;j++)
        {
            A[i][j] = str[j] - '0';
        }
    }
    int B[2001];
    cin>>str;
    for (int i = 0;i < m;i++)
        B[i] = str[i] - '0';
    int flag, cnt = 0;
    for (int i = 0;i < n;i++)
    {
        flag = 0;
        for (int j = 0;j < n;j++)
        {
            if (A[i][j] == 0)
                flag++;
            if (flag == m)
            {
                cnt++;
                flag--;
            }
            if (A[i][j] == 1)
                flag = 0;
        }
    }
    cout << cnt;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
double Cal(double r, double a, double b, double h);
int main()
{
    double r, a, b, h,ans;
    cin >> r >> a >> b >> h;
    if (2 * r < b)
        cout << "Drop" << endl;
    else
    {
        cout << "Stuck" << endl;
        ans = Cal(r, a, b, h);
        cout << setprecision(16) << ans << endl; ;
    }
}
double Cal(double r, double a, double b, double h)
{
    double a1, b1,temp,temp2;
    a1 = a / 2;
    b1 = b / 2;
    temp = (h * b1) / (a1 - b1);
    temp2 = sqrt((a1 * a1) + (h + temp) * (h + temp));

    return temp2*r/a1 - temp;

}
*/
#include<iostream>
using namespace std;
int a[100000];
int maxthree(int x) {
    if (x % 3 == 0)
        return 1;
    int xx = x;
    int str[19];
    for (int i = 0;i < 19;i++)
        str[i] = -1;
    int xn = 0;
    while (x)
    {
        xn++;
        x = x / 10;
    }
    int i = xn;
    while (xx)
    {
        str[--i] = xx % 10;
        if (str[i] % 3 == 0)
            return 1;
        xx = xx / 10;
    }
    int temp = 0;
    for (int i = 0;i < xn;i++) {
        int tmp = str[i];
        if (tmp % 3 == 0) {
            return 1;
            temp = 0;
        }
        else {
            temp += tmp;
            if (temp % 3 == 0) {
                return 1;
                temp = 0;
            }
        }
    }
    return 0;
}

/*int is3friendly(int x)
{
    if (x % 3 == 0)
        return 1;
    int xx = x;
    int a[19];
    for (int i = 0;i < 19;i++)
        a[i] = -1;
    int xn = 0;
    while (x)
    {
        xn++;
        x = x / 10;
    }
    int i = xn;
    while (xx)
    {
        a[--i] = xx % 10;
        if (a[i] % 3 == 0)
            return 1;
        xx = xx / 10;
    }
    for (int i = 0;i < xn;i++)
    {
        int xi = i;
        int kx = a[xi];
        for (int j = i + 1;j < xn;j++)
        {
            kx = kx * 10 + a[j];
            if (kx % 3 == 0)
                return 1;
        }
    }
    return 0;
}*/
int main() 
{
    int T, cnt = 0,ii=0,TT;
    cin >> T;
    TT = T;
    while (T)
    {
        int l, r;
        cin >> l >> r;
        for (int i = l;i <= r;i++)
            if (maxthree(i))
                cnt++;
        a[ii] = cnt;
        ii++;
        T--;
        cnt = 0;
    }
    for (int i = 0;i < TT;i++)
        cout << a[i]<<endl;
}


