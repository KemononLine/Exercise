#include <stdio.h>
int gcd(int a,int b);
int lcm(int a,int b);

int main(int argc, char* argv[])
{
	int n,a,b;
	scanf("%d", &n);
	scanf("%d", &a);
	for(int i=1; i<n;  i++)
	{
		scanf("%d", &b);
		lcm(a,b);
		a=lcm(a,b);
	}
	printf("%d\n", lcm(a,b));
	return 0;
}


int gcd(int a,int b)
{
	while( 1 )
	{
		int r=a%b;
		if(r==0)
			return b;
		a=b; b=r;
	}
}

int lcm(int a,int b)
{
	return a=a/gcd(a,b)*b;
}


/*
#include <stdio.h>



int main()
{
	int n,a,b;
	scanf("%d", &n);
	scanf("%d", &a);
	for(int i=1; i<n;  i++)
	{
		scanf("%d", &b);
		
		
		while( 1 )
		{
			int r=a%b;
			if(r==0)
				break;
			a=b;  b=r;
		}
		
	}
	printf("%d\n", b);

	return 0;
	

}
/*/