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
	int MaxLeftSum, MaxRightSum;    //存放左右子问题的解。
	int MaxLeftBorderSum, MaxRightBorderSum;    //存放跨分界线的结果。

	int LeftBorderSum, RightBorderSum;
	int center, i;

	/*递归的终止条件，子列只有1个数字
if (left == right)
{
	if (a[left] > 0)
		return a[left];
	else
		return 0;
}

/* “分”的过程 
center = (left + right) / 2;    //找到中分点。
MaxLeftSum = fun(a, left, center);    //递归求左子列和。
MaxRightSum = fun(a, center + 1, right);    //递归求右子列和。

求跨分界线的最大子列和
MaxLeftBorderSum = 0;	LeftBorderSum = 0;
for (i = center; i >= left; i--)
{
	LeftBorderSum += a[i];
	if (LeftBorderSum > MaxLeftBorderSum)
		MaxLeftBorderSum = LeftBorderSum;
}//左边扫描结束。

MaxRightBorderSum = 0;	RightBorderSum = 0;
for (i = center + 1; i <= right; i++)
{
	RightBorderSum += a[i];
	if (RightBorderSum > MaxRightBorderSum)
		MaxRightBorderSum = RightBorderSum;
}//右边扫描结束。

/*返回“治”的结果
return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}*/

