#include <stdio.h>

int main()
{
	int x;
	scanf("%d",&x);
	int x1=3;
	while( x1<=x-x1 )
	{
		int x2=x-x1;
		// �ж�x1�Ƿ�������
		for(int a=2; a<x1; a++)
		{
			if(x1%a==0)
				break;  
		}
		if(a>=x1)
		{
			// �ж�x2�Ƿ�������
			for(a=2; a<x2; a++)
			{
				if(x2%a==0)
					break;  
			}
			if( a>=x2 )
				printf("%d + %d = %d\n", x1,x2,x);
		}
		x1+=2;
	}
    return 0;
}

