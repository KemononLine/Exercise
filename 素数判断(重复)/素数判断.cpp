// ËØÊıÅĞ¶Ï.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void main()

{

int x,x1,cnt;

scanf("%d",&x);

for(x1=2,cnt=0;x1<x;x1++)

  if(x%x1==0) break;

if(x1>=x)

{printf("Yes");cnt++;}

else

printf("No");

printf("%d",cnt);

}
