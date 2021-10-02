/*
#include <stdio.h>
#include <string.h>

void SelectSort(char a[], int n);
int FindiMin(char a[], int si, int ei);
int stoi(char a[], int k);

int main(int argc, char* argv[])
{
	char a[8],n,min,max,ans;
	gets(a);
	n=strlen(a);
	SelectSort(a,n);
	min=stoi(a,n);
	int i,nmid,temp;
	nmid=n/2;
	for(i=0;i<nmid;i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
	max=stoi(a,n);
	ans=max-min;
	printf("%d",ans);
	return 0;    
}

//           3,6,7,4,2,8,5,1
// 第1趟   (1),6,7,4,2,8,5,3
// 第2趟   (1,2),7,4,6,8,5,3
// 第3趟   (1,2,3),4,6,8,5,7
// 第4趟   (1,2,3,4),6,8,5,7
// 第5趟   (1,2,3,4,5),8,6,7
// 第6趟   (1,2,3,4,5,6),8,7
// 第n-1趟 (1,2,3,4,5,6,7),8
void SelectSort(char a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		// 在a[i]...a[n-1]找最小值的下标imin
		int imin=FindiMin(a, i,n-1);
		// 交换a[imin] <=> a[i]
		if(imin!=i)
		{
			int tmp=a[imin]; a[imin]=a[i]; a[i]=tmp;
		}
	}
}
// 在a[si]...a[ei]找最小值的下标imin
int FindiMin(char a[], int si, int ei)
{
	int imin=si;
	for(int i=si+1; i<=ei; i++)
		if(a[i]<a[imin])
			imin=i;
	return imin;
}

int  stoi(char a[],int n)
{
	int x=0;
	for(int i=0 ; i<n ; i++)
	{
		x = x*10 + a[i]-'0'; // 1 10 101 1011....
	}
	return x;
}
/*/

#include<stdio.h>
#include<string.h>
/*
int main()
{
	char a[10000],c;
	int j,n;
	int i=0,max=0,min=0;
	gets(a);
	n=strlen(a);
	while(i<n)
	{
		for(j=i;a[j]!='\0';j++)
		{
			if(a[i]<a[j])
			{
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
		i++;
	}
	i=0;
	while(i<n)
	{
		max=max*10+(a[i]-48);
		min=min*10+(a[n-1-i]-48);
		i++;
	}
	printf("%d",max-min);
}


*/
int main()
{

printf("%3s,%6.2s,%.3s.%-5.3s","Good","Good","Good","Good");
return 0;
}
