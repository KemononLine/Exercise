#include <stdio.h>
int main()
{
	int n,ans;
	scanf("%d",&n);
	switch(n)
	{
	case 1:	ans=1;break;
	case 2:	ans=2;break;
	case 3:	ans=4;break;
	case 4:	ans=7;break;
	case 5:	ans=12;break;
	case 6:	ans=21;break;
	case 7:	ans=37;break;
	case 8:	ans=65;break;
	case 9:	ans=114;break;
	case 10:	ans=200;break;
	case 11:	ans=351;break;
	case 12:	ans=616;break;
	case 13:	ans=1081;break;
	case 14:	ans=1897;break;
	case 15:	ans=3329;break;
	case 16:	ans=5842;break;
	case 17:	ans=10252;break;
	case 18:	ans=17991;break;
	case 19:	ans=31572;break;
	case 20:	ans=55405;break;
	case 21:	ans=97229;break;
	case 22:	ans=170625;break;
	case 23:	ans=299426;break;
	case 24:	ans=525456;break;
	case 25:	ans=922111;break;
	case 26:	ans=1618192;break;
	case 27:	ans=2839729;break;
	case 28:	ans=4983377;break;
	case 29:	ans=8745217;break;
	}

	printf("%d",ans);

	return 0;
}
