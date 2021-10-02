#include <stdio.h>

void Input (int a[],int na);
void Output(int a[],int na);

int main()
{
	int a[10000];
	int na;
	
	scanf("%d",&na);
	Input(a,na);
	Output(&a[0],na);

	return 0;

}
void Input(int a[],int na)
{
	for(int i=0; i<na; i++)
		scanf("%d", &a[i]);
}

void Output(int a[],int na)
{
	int max=a[0];
	int ans;
	for(int i=0;i<na;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			ans=i;
		}
			

	}
	
	printf("%d",ans);
}