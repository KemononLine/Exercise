#include <stdio.h>
int main()
{
	puts("Please Input Estimated Value:");
	double x,ans;
	scanf("%lf",&x);
	if(x>0&&x<=25)
		ans=x*0.0055;
	else if(x>25&&x<=50)
		ans=0.1375+(x-25)*0.005;
	else if(x>50&&x<=100)
		ans=0.2625+(x-50)*0.0045;
	else if(x>100&&x<=200)
		ans=0.4875+(x-100)*0.004;
	else if(x>200&&x<=500)
		ans=0.8875+(x-200)*0.0035;
	else if(x>500&&x<=1000)
		ans=1.9375+(x-500)*0.002;
	else if(x>1000)
		ans=2.9375+(x-1000)*0.0008;

	printf("The final fee is:%lf\n",ans);

	return 0;
	
}
