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

// �ð���ɸ������������
void prime(int b) {
    //��ʼ����Ĭ��ȫ����������
    memset(book, true, sizeof(book));
    book[1] = false;//1��������
    int n = sqrt(b);
    for (int i = 2;i <= n;i++) {
        if (book[i]) {
            //�����ı������Բ��������������������ı���ȫ����Ϊfalse
            for (int j = 2;j <= b / i;j++)
                book[i * j] = false;  // i*j<=b 
        }
    }
}

//�жϻ�����
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
    //b<=10000000����ж��������ԣ�����11���⣬һ������λ����ż���Ļ���������Ϊ������������
    // ���һ������������λ����ż��������������λ�ϵ����ֺ���ż��λ�ϵ����ֺͱ�Ȼ��ȣ�
    // �����������������ۣ������ж����������϶��ܱ�11�������������Ͳ�������������
    if (b >= 10000000)
        b = 9999999;

    prime(b);

    if (a > b)
        return 0;

    if (a % 2 == 0) a++;//����2���⣬2�ı���������������
    for (int i = a;i <= b;i += 2) {
        if (book[i] && isHWS(i))
            cout << i << endl;//�����������ͬʱҲ�ǻ��������������
    }
    return 0;
}
*/