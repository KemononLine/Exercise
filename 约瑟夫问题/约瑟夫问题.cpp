#include <stdio.h>
int Joseph(int n,int m)
{
    if(n == 2)//���ñ߽�ֵ
    {
        if(m % 2 == 0)
            return 1;
        else
            return 2;
    }
    else
    {
        return (Joseph(n-1,m) + m-1) % n+1;//�ݹ����
    }
}

int main()
{
    int n,m,x;
    scanf("%d %d",&n,&m);
    x=Joseph(n,m);
    printf("%d\n",x);
    return 0;
}
