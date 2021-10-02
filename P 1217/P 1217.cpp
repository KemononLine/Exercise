#include <iostream>
#include <ctime>

using namespace std;

bool Palin(int obj);
bool Prime(int obj);

int main()
{
	int a, b;
	cin >> a >> b;
	int i = a;
	while (i <= b)
	{
		if (Palin(i))
		{
			if (Prime(i))
			{
				cout << i << endl;
			}
		}
        if (i == 9989899)
            break;
        if (a == 1)
            i += 2;
        else
            i++;
	}

	return 0;
}

bool Palin(int obj)
{
	int temp=0,vert=0,obj2;
	obj2 = obj;
	while (obj > 0)
	{
		temp = obj % 10;
		vert = (temp + vert) * 10;
		obj /= 10;
	}
	vert /= 10;
	if (vert == obj2)
		return true;
	else
		return false;
}

bool Prime(int obj)
{
	for (int i = 2;i * i <= obj;i++)
		if (!(obj % i))
			return false;
	return true;
}
/*
bool book[100000001];

// 用埃氏筛法生成质数表
void prime(int b) {
    //初始化，默认全部都是质数
    memset(book, true, sizeof(book));
    book[1] = false;//1不是质数
    int n = sqrt(b);
    for (int i = 2;i <= n;i++) {
        if (book[i]) {
            //质数的倍数绝对不是质数，把所有质数的倍数全部设为false
            for (int j = 2;j <= b / i;j++)
                book[i * j] = false;  // i*j<=b 
        }
    }
}

//判断回文数
bool isHWS(int num) {

    int temp = num, ans = 0;
    while (temp != 0) {
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    if (ans == num)
        return true;
    else
        return false;
}

int main() {
    int a, b;
    cin >> a >> b;
    //b<=10000000这个判断条件来自：除了11以外，一个数的位数是偶数的话，不可能为回文数素数。
    // 如果一个回文素数的位数是偶数，则它的奇数位上的数字和与偶数位上的数字和必然相等；
    // 根据数的整除性理论，容易判断这样的数肯定能被11整除，所以它就不可能是素数。
    if (b >= 10000000)
        b = 9999999;

    prime(b);

    if (a > b)
        return 0;

    if (a % 2 == 0) a++;//除了2以外，2的倍数不可能是质数
    for (int i = a;i <= b;i += 2) {
        if (book[i] && isHWS(i))
            cout << i << endl;//如果既是质数同时也是回文数，就输出。
    }
    return 0;
}
*/