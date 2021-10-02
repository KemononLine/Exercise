//高精度合集（我把它做成了一个小程序，大家复制下来运行） 
#include <stdio.h>    //标准输入输出头文件 
#include <string.h>   //字符串头文件 
#include <math.h>     //数学函数 
#include <stdlib.h>
char s[10001],ss[10001];   //定义全局变量供下面的程序使用 
int a[10001],b[10001],c[10001];
char arr[1000000],cha[1000000];
int d,len;

int Compare(char a[],char b[])     //比较字符串的大小，方法不同于strcmp函数，类似于整型常量的比较
{
	
	int lena,lenb,i;
	lena=strlen(a);         //a的长度 
	lenb=strlen(b);         //b的长度 
	if(lena<lenb) 
		return -1;      //如果a的长度比b小，返回-1 
	else if(lena>lenb) 
		return 1;       //不是，返回1 
	else
	{
		if(strcmp(a,b)==0)     
			return 0;
		else
		{ 
			for(i=0;i<lena;i++)
			{ 
				if(a[i]>b[i]) 
					return 1;
				if(a[i]<b[i]) 
					return -1;
			}
			return 0;
		}
	}
}

int Judge(char ch[])         //判断字符串ch是否全为0，若全为0，返回1，否则返回0
{
	int i,k;
	k=strlen(ch);
	for(i=0;i<k;i++) 
		if(ch[i]!='0') 
			return 0;
		return 1;
}

/*-------------高精度加法--------------*/
void jia()     //自定义函数"jia"(名字low了一点（好像不是一点，但容易理解不是吗）) 
{
	int l1 = strlen(s);     //"strlen"是一个计算字符串长度的函数 
	int l2 = strlen(ss);    //将输入的两个字符串的长度赋值给l1,l2
	if (l1 > l2) 
		len = l1;      //将len赋值为l1,l2中大的那个 
	else 
		len = l2;
//		for (int i = 0 ; i <= len ; i++)  //清零（这里for循环和下面三句memset都为将字符串清零 ） 
//			a[i] = b[i] = c[i] = 0;
	memset(a,0,sizeof(a));    //清零too(只能清零，不能干别的) 
	memset(b,0,sizeof(b));    //这是清零函数（字符串）
	                                       //两个for循环是将输入的两个字符串倒过来
	for (int i = l1 - 1 ; i >= 0 ; i--)    //再将字符串里的字符转换为数字赋值给a,b整型数组 
		a[l1 - i - 1] = s[i] - '0';        //但为什么大数要用字符串存呢？
	for (int i = l2 - 1 ; i >= 0 ; i--)    //因为大数太大，用任何整型变量都存不下 
		b[l2 - i - 1] = ss[i] - '0';       //为什么要把字符串倒过来赋值呢？ 
	                                //因为大数与大数是一位一位运算的，还要涉及进位等 
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] + b[i];    //运算 
		a[i+1]+= a[i] / 10;    //如有进位，在后一位上加上 
		a[i] = a[i] % 10;      //原来那一位减掉进位了的 
	}
	if (a[len] != 0) 
		len++;    //如果有进位就多显示一位（这句话很重要）
	printf("结果：\n");
	printf("%s + %s = ",s,ss); 
	for (int i = len - 1 ;i >= 0 ;i--)  //输出结果 
		printf("%d",a[i]);
	printf("\n");
}                              //高精度加法你懂了吗？ 


/*-------------高精度减法--------------*/	
void jian()
{
	int l1 = strlen(s);    //字符串长度 
	int l2 = strlen(ss);
	int flag = 0;         //一个记录正负的变量（后面就知道啦） 
	
	memset(a,0,sizeof(a));       
	memset(b,0,sizeof(b));		
	
	if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )    //这个比较重要是来判断前后两数的大小的  
	{                                           //不然一个小的数减一个大的数是大于零的就尴尬了
		flag = 1; //这里是把正负记录下来  
		for (int i = l2 - 1 ; i >= 0 ; i--)    //倒过来输入 
			a[l2 - i - 1] = ss[i] - '0';      //将字符串里的字符转换为数字 
		for (int i = l1 - 1 ; i >= 0 ; i--)
			b[l1 - i - 1] = s[i] - '0';
	}
	else
	{
		for (int i = l1 - 1 ; i >= 0 ; i--)   //同理，倒过来输入 
			a[l1 - i - 1] = s[i] - '0';
		for (int i = l2 - 1 ; i >= 0 ; i--)
			b[l2 - i - 1] = ss[i] - '0';
	}
	if (l1 > l2) 
		len = l1;             //len赋值为其中大的数 
	else 
		len = l2; 
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] - b[i];     //运算 
		if (a[i] < 0)          //如果减得多了 
		{
			a[i+1]-=1;         //向前要一位 
			a[i]+=10;          
		}
	}
	
	while (a[len - 1] == 0 && len>1) 
		len--;   //while去零法，了解一下（名字现编的，别搜百度了）
	printf("结果：\n"); 
	printf("%s - %s = ",s,ss);
	if (flag == 1) 
		printf("-");     //如果结果是负的，先输出一个负号
	for (int i = len - 1 ;i >= 0 ;i--)   //再输出结果 
		printf("%d",a[i]);
	printf("\n");   //换行 
}                           //高精度减法你懂了吗？ 


/*-------------高精度乘法（低）--------------*/	
void cheng_di()    //这里的低是指高精度乘低精度，OK？ 
{
	len = strlen(s);       //记录字符长长度（这里只有一个字符串） 
	memset(a,0,sizeof(a));   //清空数组 	
	for (int i = 0 ; i < len ; i++)    //将字符串里的字符转换为数字
		a[len - i - 1] = s[i] - '0';
	int jinwei = 0;
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] * d + jinwei;    //运算 
		jinwei = a[i] / 10;      //进位 
		a[i] %= 10;
	}
	
	if (jinwei != 0)
	{
		a[len] = jinwei;       //将进位后的数字保存在最后一位 
		len++;          //并把位数+1 
		while (a[len - 1] >= 10)
		{
			a[len] = a[len - 1] / 10;    //把进位搞好后再把后面的数字也弄好 
			a[len - 1] %= 10;
			len++;     //把位数++ 
		}
	}
	while (a[len - 1] == 0 && len > 1) 
		len--;     //while去零法 
	printf("结果：\n");
	printf("%s × %d = ",s,d);
	for (int i = len - 1 ; i >= 0; i--)    //输出结果 
		printf("%d",a[i]);
	printf("\n");     //换行 
}                               //高精度乘法（低）你懂了吗 


/*-------------高精度乘法（高）--------------*/	
void cheng_gao()     //高是指高精度乘高精度 
{
	len = strlen(s);
	memset(a,0,sizeof(a));   
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));	
	for (int i = 0 ; i < len ; i++)
		a[len - i - 1] = s[i] - '0';    //转化 
	int lenn = strlen(ss);
	for (int i = 0 ; i < lenn ; i++)
		b[lenn - i - 1] = ss[i] - '0';
		
	memset(c,0,sizeof(c));   //清零 
	for (int i = 0 ; i < len ; i++)
		for (int j = 0 ; j < lenn ; j++)
			c[i + j] += a[i] * b[j];       //运算（这个就有一点复杂了） 
		
	int l = len + lenn - 1;    //l是结果的最高位数 
	for (int i = 0 ; i < l ;i++)
	{
		c[i + 1] += c[i] / 10;    //保证每一位的数都只有一位，并进位 
		c[i] %= 10;
	}
	if (c[l] > 0) l++;     //保证最高位数是对的 
	while (c[l - 1] >= 10)
	{
		c[l] = c[l - 1] / 10;
		c[l - 1] %= 10;
		l++;
	}
	while (c[l - 1] == 0 && l > 1) 
		l--;    //while去零法 
	printf("结果：\n");
	printf("%s × %s = ",s,ss);
	for (int i = l - 1; i >= 0 ; i--)    //输出结果 
		printf("%d",c[i]);
	printf("\n");     //换行 
}                               //高精度乘法（高）你懂了吗
	

/*-------------高精度除法（低）--------------*/	
void chu_di()       //高精除低精 
{
	int yu=0;
	memset(a,0,sizeof(a));    //清空数组a 
	memset(b,0,sizeof(b));    //清空数组b 
	len=strlen(s);            //s的长度 
	for(int i=0;i<=len-1;i++)     //将 
		a[i+1]=s[i]-'0';
	for(int ii=1;ii<=len;ii++)
	{
		b[ii]=(yu*10+a[ii])/d;
		yu=(yu*10+a[ii])%d;
	}
	int lenb=1;
	while(b[lenb]==0&&lenb<len)
		lenb++;
	printf("结果：\n");
	printf("%s ÷ %d = ",s,d);
	for(int j=lenb;j<=len;j++)
		printf("%d",b[j]);
	if(yu!=0)
		printf("......%d",yu);
	printf("\n");       
}


/*-------------高精度除法（高）--------------*/
void Sub(char a1[],char b1[])     
{//a1为被减数，b1为减数
	
	int lena,lenb,i,j,k,flag;
	int a[1000]={0},b[1000]={0},d[1000]={0};
	lena=strlen(a1);
	lenb=strlen(b1);
	if(Compare(a1,b1)>=0) 
	{//若被减数大于等于减数
		for(i=0;i<lena;i++)  a[i]=a1[lena-1-i]-'0';
		for(i=0;i<lenb;i++)  b[i]=b1[lenb-1-i]-'0';
		flag=0;//结果正的标志
	}
	else 
	{//若被减数小于减数
		for(i=0;i<lenb;i++) a[i]=b1[lenb-1-i]-'0';
		for(i=0;i<lena;i++)  b[i]=a1[lena-1-i]-'0';
		flag=1;//结果负的标志
	}
	k=lena>lenb?lena:lenb;
	for(i=0;i<k;i++)
	{//大数减小数
		if(a[i]<b[i])
		{//若被减数不够减，向高位借一位
			a[i+1]--;
			d[i]=a[i]-b[i]+10; 
		}
		else  d[i]=a[i]-b[i];
	}
	//若较高位已为，并且不止位时
	while(!d[i-1])
	{  k--; i--;  }
	//根据flag，输出有无"-"
	if(!flag)
	{ 
		for(i=0;i<k;i++)
		{//将结果转化为字符逆着赋给数组c
			
			if(!i&&!d[k-i-1])//若差的第一个字母为0，则马上跳过
				
				continue;
			
			cha[i]=d[k-i-1]+'0'; 
		} 
	}
	else 
	{ 
		cha[0]='-'; 
		for(i=1;i<=k;i++)
		{//将结果转化为字符逆着赋给数组c
			if(i==1&&!d[k-i])//若差的第一个字母为，则马上跳过
				continue;
			cha[i]=d[k-i]+'0';//注意d的下标，不是k-i-1
		}
	}
	if(Judge(cha))//若差全为，则只输出一个
		strcpy(cha,"0");
}

void chu_gao()
{
	char a[1000],b[1000],t[1000];
	int lens,lent,i,j,k,flag=0;
    memset(arr,0,sizeof(arr));
	if(Compare(s,ss)<0)   //若被除数小于除数，则商为0，余数为被除数
		strcpy(arr,s);
	else if(!Compare(s,ss)) //若两数相等，则商为1，余数为0
		cha[0]='1';
	else         //若被除数大于除数
	{ 
		j=lent=0; lens=strlen(s); 
		memset(b,0,sizeof(b)); 
		memset(t,0,sizeof(t));
		for(i=0;i<lens;i++)   //计算得到被除数的前几位,得到整型数组形式的商
		                      //t的一个元素表示一次相除的商
		{
			b[j++]=s[i]; 
			flag=0;
			while(Compare(b,ss)>=0)
			{
				Sub(b,ss);
				strcpy(b,cha);
				memset(cha,0,sizeof(cha));
				t[lent]++;
				flag=1;            //控制t的元素的位置
			}
			if(flag)               //将商转换为字符
				t[lent]+='0';
			else                  //当被除数前几位小于除数，商补	
				t[lent]='0';
			if(!strcmp(b,"0"))     //若b为''	
				j=0;
			else             //继续在b的后面加值	
				j=strlen(b);
			lent++; 
		}
		k=0;
		for(i=0;i<lent;i++)
			
			if(t[i]!='0')
				break;           //找到t数组中第一个不为0的位置
			for(j=i;j<lent;j++) 
				cha[k++]=t[j];
			strcpy(arr,b); 
	}
	if(Judge(cha))
		strcpy(cha,"0");
	if(Judge(arr))
		strcpy(arr,"0");
}


/*-------------高精度阶乘--------------*/     //这个函数不是我写的，特此申明，侵删 
unsigned int *x;    //动态数组 
/* 求N!的位数公式 log10(1)+log10(2)+···+log10(n) 取整加1  */
int wei(int d)
{
	int i;
	double sum=0;
	for(i=1;i<=d;i++) sum+=log10((double)i);
	/* 以万为进制，一位可以表示4个数，减少存储空间 */
	return (int)((sum+1)/4+1);
}

void jiecheng()
{
	int i,j,jinwei,weishu=1,temp;
	/* 依据阶乘位数申请动态数组 */
	x=(unsigned int*) malloc(wei(d)*sizeof(int));
	x[0]=1;
	if(d>30000)
		printf("\n这数字太大了！\n可能有点慢，稍等！\n");
	else 
	if(d>2000)
		printf("\n这数字有点大呀！\n\n"); 
	for(i=2;i<=d;i++)
	{
		jinwei=0;
		for(j=1;j<=weishu;j++)
		{
			temp=x[j-1]*i+jinwei;
			if (temp>=1)
			{
				/* 以万为进制，提高运算速度 */
				x[j-1]=temp%10000;
				jinwei=temp/10000;
			}
		}
		while(jinwei)
		{
			weishu++;
			x[weishu-1]=jinwei%10000;
			jinwei/=10000;
		}
	}
	printf("结果：\n");
	/* 先输出第一个数，防止首位出现0 */
	printf("%d ! = ",d);
	printf("%d",x[weishu-1]);
	/* 输出其余的数，因为万进制，需要补0 */
	for(j=weishu-2;j>=0;j--) printf("%04d",x[j]);
	/* 释放申请的内存 */
	free(x);	
} 


void print()
{
	printf("...............高精度模板(By STY)...............\n");
	printf("高精度加法请打“1”\n");
	printf("高精度减法请打“2”\n");
	printf("高精度乘法(低)请打“3”\n");
	printf("高精度乘法(高)请打“4”\n");
	printf("高精度除法(低)请打“5”\n");
	printf("高精度除法(高)请打“6”\n");
	printf("高精度阶乘请打“7”\n");
	printf("退出请按“Ctrl+Z”(在键盘上)，并按回车，谢谢使用！\n");
	printf("请输入：（1~7）\n");
}

void print_jia()
{
	printf("\n您选择了：高精度加法\n"); 
	printf("请输入两个数字：\n");
	printf("数字：\n");
	scanf("%s%s",s,ss);
	jia();     //引用高精度加法函数 
}

void print_jian()
{
	printf("\n您选择了：高精度减法\n"); 
	printf("请输入两个数字：\n");
	printf("数字：\n");
	scanf("%s%s",s,ss);
	jian();    //引用高精度减法函数
}

void print_cheng_di()
{
	printf("\n您选择了：高精度乘法（低）\n"); 
	printf("请输入两个数字：\n");
	printf("数字：\n");
	scanf("%s%d",s,&d);
	cheng_di();    //引用高精度乘法（低）函数  
}

void print_cheng_gao()
{
	printf("\n您选择了：高精度乘法（高）\n"); 
	printf("请输入两个数字：\n");
	printf("数字：\n");
	scanf("%s%s",s,ss);
	cheng_gao();   //引用高精度乘法（高）函数
}

void print_chu_di()
{
	printf("\n您选择了：高精度除法（低）\n"); 
	printf("请输入两个数字：\n");
	printf("数字：\n");
	scanf("%s%d",s,&d);
	chu_di();   //引用高精度除法（低）函数 
}

void print_chu_gao()
{
	printf("\n您选择了：高精度除法（高）\n"); 
	printf("请输入两个数字：\n");
	printf("数字：\n");
	scanf("%s%s",s,ss); 
	if(Judge(ss)) 
		printf("0不能作除数。\n\n");
	else 
	{ 
		chu_gao();     //引用高精度除法（高）函数
		if(!Judge(arr))
			printf("%s / %s=%s......%s\n\n",s,ss,cha,arr);
		else 
			printf("%s / %s=%s\n\n",s,ss,cha);  //如果没有余数就不输出 
	}
} 

void print_jiecheng()
{
	printf("\n您选择了：高精度阶乘\n"); 
	printf("请输入一个数字：\n");
	printf("这个数字最好别超过120000，不然太慢，等不起（可能要算几十分钟）\n");
	printf("数字：\n");
	scanf("%d",&d);
	jiecheng();   //引用高精度阶乘函数 
} 

/*-------------主程序--------------*/		
int main()   
{
	int choice,i;
//原来将print中的代码上面写一遍，下面复制一遍，后写成了函数 
	print();
	while(scanf("%d",&choice)!=EOF)    //这个程序可循环 
	{	
//		if(choice==1)      
//			print_jia();
//		else if(choice==2)
//			print_jian();
//		else if(choice==3)
//			print_cheng_di();
//		else if(choice==4)
//			print_cheng_gao();
//		else if(choice==5)
//			print_chu_di();
//		else if(choice==6)
//			print_chu_gao();
//		else if(choice==7)
//			print_jiecheng(); 
//      else
//			printf("没有这一项！别开玩笑了！\n");     

//上面注释的那一段和下面用switch-case的代码是一个意思		
		switch(choice) 
		{
			case 1:print_jia();break;
			case 2:print_jian();break;
			case 3:print_cheng_di();break;
			case 4:print_cheng_gao();break;
			case 5:print_chu_di();break;
			case 6:print_chu_gao();break;
			case 7:print_jiecheng();break;
			default:printf("没有这一项！别开玩笑了！\n");break;  
		}
		printf("\n\n");		//空行 
		print();
	}	
	return 0;
}