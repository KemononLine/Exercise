#include <iostream>
using namespace std;

int main()
{

}


/*
int main()
{
	int a[100005], n, thisSum = 0, maxSum = 0,left=0,right=0,temp=0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		thisSum += a[i];
		if (thisSum > maxSum)
		{
			maxSum = thisSum;
			right = i;
		}

		else if (thisSum < 0)
		{
			thisSum = 0;
		}

	}
	for (int i = right;i >= 0;i--)
	{
		temp += a[i];
		if (temp == maxSum)
		{
			left = i;
			break;
		}
	}
	cout << maxSum << " " << a[left] << " " << a[right];

	return 0;
}


int fun(int a[], int left, int right);
int Max3(int a, int b, int c);
int a[10005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	cout << fun(a, 0, n);

}

int Max3(int a, int b, int c)
{
	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int fun(int a[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;    //�������������Ľ⡣
	int MaxLeftBorderSum, MaxRightBorderSum;    //��ſ�ֽ��ߵĽ����

	int LeftBorderSum, RightBorderSum;
	int center, i;

	/*�ݹ����ֹ����������ֻ��1������
if (left == right)
{
	if (a[left] > 0)
		return a[left];
	else
		return 0;
}

/* ���֡��Ĺ��� 
center = (left + right) / 2;    //�ҵ��зֵ㡣
MaxLeftSum = fun(a, left, center);    //�ݹ��������к͡�
MaxRightSum = fun(a, center + 1, right);    //�ݹ��������к͡�

���ֽ��ߵ�������к�
MaxLeftBorderSum = 0;	LeftBorderSum = 0;
for (i = center; i >= left; i--)
{
	LeftBorderSum += a[i];
	if (LeftBorderSum > MaxLeftBorderSum)
		MaxLeftBorderSum = LeftBorderSum;
}//���ɨ�������

MaxRightBorderSum = 0;	RightBorderSum = 0;
for (i = center + 1; i <= right; i++)
{
	RightBorderSum += a[i];
	if (RightBorderSum > MaxRightBorderSum)
		MaxRightBorderSum = RightBorderSum;
}//�ұ�ɨ�������

/*���ء��Ρ��Ľ��
return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}*/

