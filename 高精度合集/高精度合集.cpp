//�߾��Ⱥϼ����Ұ���������һ��С���򣬴�Ҹ����������У� 
#include <stdio.h>    //��׼�������ͷ�ļ� 
#include <string.h>   //�ַ���ͷ�ļ� 
#include <math.h>     //��ѧ���� 
#include <stdlib.h>
char s[10001],ss[10001];   //����ȫ�ֱ���������ĳ���ʹ�� 
int a[10001],b[10001],c[10001];
char arr[1000000],cha[1000000];
int d,len;

int Compare(char a[],char b[])     //�Ƚ��ַ����Ĵ�С��������ͬ��strcmp���������������ͳ����ıȽ�
{
	
	int lena,lenb,i;
	lena=strlen(a);         //a�ĳ��� 
	lenb=strlen(b);         //b�ĳ��� 
	if(lena<lenb) 
		return -1;      //���a�ĳ��ȱ�bС������-1 
	else if(lena>lenb) 
		return 1;       //���ǣ�����1 
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

int Judge(char ch[])         //�ж��ַ���ch�Ƿ�ȫΪ0����ȫΪ0������1�����򷵻�0
{
	int i,k;
	k=strlen(ch);
	for(i=0;i<k;i++) 
		if(ch[i]!='0') 
			return 0;
		return 1;
}

/*-------------�߾��ȼӷ�--------------*/
void jia()     //�Զ��庯��"jia"(����low��һ�㣨������һ�㣬��������ⲻ����) 
{
	int l1 = strlen(s);     //"strlen"��һ�������ַ������ȵĺ��� 
	int l2 = strlen(ss);    //������������ַ����ĳ��ȸ�ֵ��l1,l2
	if (l1 > l2) 
		len = l1;      //��len��ֵΪl1,l2�д���Ǹ� 
	else 
		len = l2;
//		for (int i = 0 ; i <= len ; i++)  //���㣨����forѭ������������memset��Ϊ���ַ������� �� 
//			a[i] = b[i] = c[i] = 0;
	memset(a,0,sizeof(a));    //����too(ֻ�����㣬���ܸɱ��) 
	memset(b,0,sizeof(b));    //�������㺯�����ַ�����
	                                       //����forѭ���ǽ�����������ַ���������
	for (int i = l1 - 1 ; i >= 0 ; i--)    //�ٽ��ַ�������ַ�ת��Ϊ���ָ�ֵ��a,b�������� 
		a[l1 - i - 1] = s[i] - '0';        //��Ϊʲô����Ҫ���ַ������أ�
	for (int i = l2 - 1 ; i >= 0 ; i--)    //��Ϊ����̫�����κ����ͱ������治�� 
		b[l2 - i - 1] = ss[i] - '0';       //ΪʲôҪ���ַ�����������ֵ�أ� 
	                                //��Ϊ�����������һλһλ����ģ���Ҫ�漰��λ�� 
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] + b[i];    //���� 
		a[i+1]+= a[i] / 10;    //���н�λ���ں�һλ�ϼ��� 
		a[i] = a[i] % 10;      //ԭ����һλ������λ�˵� 
	}
	if (a[len] != 0) 
		len++;    //����н�λ�Ͷ���ʾһλ����仰����Ҫ��
	printf("�����\n");
	printf("%s + %s = ",s,ss); 
	for (int i = len - 1 ;i >= 0 ;i--)  //������ 
		printf("%d",a[i]);
	printf("\n");
}                              //�߾��ȼӷ��㶮���� 


/*-------------�߾��ȼ���--------------*/	
void jian()
{
	int l1 = strlen(s);    //�ַ������� 
	int l2 = strlen(ss);
	int flag = 0;         //һ����¼�����ı����������֪������ 
	
	memset(a,0,sizeof(a));       
	memset(b,0,sizeof(b));		
	
	if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )    //����Ƚ���Ҫ�����ж�ǰ�������Ĵ�С��  
	{                                           //��Ȼһ��С������һ��������Ǵ�����ľ�������
		flag = 1; //�����ǰ�������¼����  
		for (int i = l2 - 1 ; i >= 0 ; i--)    //���������� 
			a[l2 - i - 1] = ss[i] - '0';      //���ַ�������ַ�ת��Ϊ���� 
		for (int i = l1 - 1 ; i >= 0 ; i--)
			b[l1 - i - 1] = s[i] - '0';
	}
	else
	{
		for (int i = l1 - 1 ; i >= 0 ; i--)   //ͬ������������ 
			a[l1 - i - 1] = s[i] - '0';
		for (int i = l2 - 1 ; i >= 0 ; i--)
			b[l2 - i - 1] = ss[i] - '0';
	}
	if (l1 > l2) 
		len = l1;             //len��ֵΪ���д���� 
	else 
		len = l2; 
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] - b[i];     //���� 
		if (a[i] < 0)          //������ö��� 
		{
			a[i+1]-=1;         //��ǰҪһλ 
			a[i]+=10;          
		}
	}
	
	while (a[len - 1] == 0 && len>1) 
		len--;   //whileȥ�㷨���˽�һ�£������ֱ�ģ����Ѱٶ��ˣ�
	printf("�����\n"); 
	printf("%s - %s = ",s,ss);
	if (flag == 1) 
		printf("-");     //�������Ǹ��ģ������һ������
	for (int i = len - 1 ;i >= 0 ;i--)   //�������� 
		printf("%d",a[i]);
	printf("\n");   //���� 
}                           //�߾��ȼ����㶮���� 


/*-------------�߾��ȳ˷����ͣ�--------------*/	
void cheng_di()    //����ĵ���ָ�߾��ȳ˵;��ȣ�OK�� 
{
	len = strlen(s);       //��¼�ַ������ȣ�����ֻ��һ���ַ����� 
	memset(a,0,sizeof(a));   //������� 	
	for (int i = 0 ; i < len ; i++)    //���ַ�������ַ�ת��Ϊ����
		a[len - i - 1] = s[i] - '0';
	int jinwei = 0;
	for (int i = 0 ; i < len ; i++)
	{
		a[i] = a[i] * d + jinwei;    //���� 
		jinwei = a[i] / 10;      //��λ 
		a[i] %= 10;
	}
	
	if (jinwei != 0)
	{
		a[len] = jinwei;       //����λ������ֱ��������һλ 
		len++;          //����λ��+1 
		while (a[len - 1] >= 10)
		{
			a[len] = a[len - 1] / 10;    //�ѽ�λ��ú��ٰѺ��������ҲŪ�� 
			a[len - 1] %= 10;
			len++;     //��λ��++ 
		}
	}
	while (a[len - 1] == 0 && len > 1) 
		len--;     //whileȥ�㷨 
	printf("�����\n");
	printf("%s �� %d = ",s,d);
	for (int i = len - 1 ; i >= 0; i--)    //������ 
		printf("%d",a[i]);
	printf("\n");     //���� 
}                               //�߾��ȳ˷����ͣ��㶮���� 


/*-------------�߾��ȳ˷����ߣ�--------------*/	
void cheng_gao()     //����ָ�߾��ȳ˸߾��� 
{
	len = strlen(s);
	memset(a,0,sizeof(a));   
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));	
	for (int i = 0 ; i < len ; i++)
		a[len - i - 1] = s[i] - '0';    //ת�� 
	int lenn = strlen(ss);
	for (int i = 0 ; i < lenn ; i++)
		b[lenn - i - 1] = ss[i] - '0';
		
	memset(c,0,sizeof(c));   //���� 
	for (int i = 0 ; i < len ; i++)
		for (int j = 0 ; j < lenn ; j++)
			c[i + j] += a[i] * b[j];       //���㣨�������һ�㸴���ˣ� 
		
	int l = len + lenn - 1;    //l�ǽ�������λ�� 
	for (int i = 0 ; i < l ;i++)
	{
		c[i + 1] += c[i] / 10;    //��֤ÿһλ������ֻ��һλ������λ 
		c[i] %= 10;
	}
	if (c[l] > 0) l++;     //��֤���λ���ǶԵ� 
	while (c[l - 1] >= 10)
	{
		c[l] = c[l - 1] / 10;
		c[l - 1] %= 10;
		l++;
	}
	while (c[l - 1] == 0 && l > 1) 
		l--;    //whileȥ�㷨 
	printf("�����\n");
	printf("%s �� %s = ",s,ss);
	for (int i = l - 1; i >= 0 ; i--)    //������ 
		printf("%d",c[i]);
	printf("\n");     //���� 
}                               //�߾��ȳ˷����ߣ��㶮����
	

/*-------------�߾��ȳ������ͣ�--------------*/	
void chu_di()       //�߾����;� 
{
	int yu=0;
	memset(a,0,sizeof(a));    //�������a 
	memset(b,0,sizeof(b));    //�������b 
	len=strlen(s);            //s�ĳ��� 
	for(int i=0;i<=len-1;i++)     //�� 
		a[i+1]=s[i]-'0';
	for(int ii=1;ii<=len;ii++)
	{
		b[ii]=(yu*10+a[ii])/d;
		yu=(yu*10+a[ii])%d;
	}
	int lenb=1;
	while(b[lenb]==0&&lenb<len)
		lenb++;
	printf("�����\n");
	printf("%s �� %d = ",s,d);
	for(int j=lenb;j<=len;j++)
		printf("%d",b[j]);
	if(yu!=0)
		printf("......%d",yu);
	printf("\n");       
}


/*-------------�߾��ȳ������ߣ�--------------*/
void Sub(char a1[],char b1[])     
{//a1Ϊ��������b1Ϊ����
	
	int lena,lenb,i,j,k,flag;
	int a[1000]={0},b[1000]={0},d[1000]={0};
	lena=strlen(a1);
	lenb=strlen(b1);
	if(Compare(a1,b1)>=0) 
	{//�����������ڵ��ڼ���
		for(i=0;i<lena;i++)  a[i]=a1[lena-1-i]-'0';
		for(i=0;i<lenb;i++)  b[i]=b1[lenb-1-i]-'0';
		flag=0;//������ı�־
	}
	else 
	{//��������С�ڼ���
		for(i=0;i<lenb;i++) a[i]=b1[lenb-1-i]-'0';
		for(i=0;i<lena;i++)  b[i]=a1[lena-1-i]-'0';
		flag=1;//������ı�־
	}
	k=lena>lenb?lena:lenb;
	for(i=0;i<k;i++)
	{//������С��
		if(a[i]<b[i])
		{//�������������������λ��һλ
			a[i+1]--;
			d[i]=a[i]-b[i]+10; 
		}
		else  d[i]=a[i]-b[i];
	}
	//���ϸ�λ��Ϊ�����Ҳ�ֹλʱ
	while(!d[i-1])
	{  k--; i--;  }
	//����flag���������"-"
	if(!flag)
	{ 
		for(i=0;i<k;i++)
		{//�����ת��Ϊ�ַ����Ÿ�������c
			
			if(!i&&!d[k-i-1])//����ĵ�һ����ĸΪ0������������
				
				continue;
			
			cha[i]=d[k-i-1]+'0'; 
		} 
	}
	else 
	{ 
		cha[0]='-'; 
		for(i=1;i<=k;i++)
		{//�����ת��Ϊ�ַ����Ÿ�������c
			if(i==1&&!d[k-i])//����ĵ�һ����ĸΪ������������
				continue;
			cha[i]=d[k-i]+'0';//ע��d���±꣬����k-i-1
		}
	}
	if(Judge(cha))//����ȫΪ����ֻ���һ��
		strcpy(cha,"0");
}

void chu_gao()
{
	char a[1000],b[1000],t[1000];
	int lens,lent,i,j,k,flag=0;
    memset(arr,0,sizeof(arr));
	if(Compare(s,ss)<0)   //��������С�ڳ���������Ϊ0������Ϊ������
		strcpy(arr,s);
	else if(!Compare(s,ss)) //��������ȣ�����Ϊ1������Ϊ0
		cha[0]='1';
	else         //�����������ڳ���
	{ 
		j=lent=0; lens=strlen(s); 
		memset(b,0,sizeof(b)); 
		memset(t,0,sizeof(t));
		for(i=0;i<lens;i++)   //����õ���������ǰ��λ,�õ�����������ʽ����
		                      //t��һ��Ԫ�ر�ʾһ���������
		{
			b[j++]=s[i]; 
			flag=0;
			while(Compare(b,ss)>=0)
			{
				Sub(b,ss);
				strcpy(b,cha);
				memset(cha,0,sizeof(cha));
				t[lent]++;
				flag=1;            //����t��Ԫ�ص�λ��
			}
			if(flag)               //����ת��Ϊ�ַ�
				t[lent]+='0';
			else                  //��������ǰ��λС�ڳ������̲�	
				t[lent]='0';
			if(!strcmp(b,"0"))     //��bΪ''	
				j=0;
			else             //������b�ĺ����ֵ	
				j=strlen(b);
			lent++; 
		}
		k=0;
		for(i=0;i<lent;i++)
			
			if(t[i]!='0')
				break;           //�ҵ�t�����е�һ����Ϊ0��λ��
			for(j=i;j<lent;j++) 
				cha[k++]=t[j];
			strcpy(arr,b); 
	}
	if(Judge(cha))
		strcpy(cha,"0");
	if(Judge(arr))
		strcpy(arr,"0");
}


/*-------------�߾��Ƚ׳�--------------*/     //�������������д�ģ��ش���������ɾ 
unsigned int *x;    //��̬���� 
/* ��N!��λ����ʽ log10(1)+log10(2)+������+log10(n) ȡ����1  */
int wei(int d)
{
	int i;
	double sum=0;
	for(i=1;i<=d;i++) sum+=log10((double)i);
	/* ����Ϊ���ƣ�һλ���Ա�ʾ4���������ٴ洢�ռ� */
	return (int)((sum+1)/4+1);
}

void jiecheng()
{
	int i,j,jinwei,weishu=1,temp;
	/* ���ݽ׳�λ�����붯̬���� */
	x=(unsigned int*) malloc(wei(d)*sizeof(int));
	x[0]=1;
	if(d>30000)
		printf("\n������̫���ˣ�\n�����е������Եȣ�\n");
	else 
	if(d>2000)
		printf("\n�������е��ѽ��\n\n"); 
	for(i=2;i<=d;i++)
	{
		jinwei=0;
		for(j=1;j<=weishu;j++)
		{
			temp=x[j-1]*i+jinwei;
			if (temp>=1)
			{
				/* ����Ϊ���ƣ���������ٶ� */
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
	printf("�����\n");
	/* �������һ��������ֹ��λ����0 */
	printf("%d ! = ",d);
	printf("%d",x[weishu-1]);
	/* ��������������Ϊ����ƣ���Ҫ��0 */
	for(j=weishu-2;j>=0;j--) printf("%04d",x[j]);
	/* �ͷ�������ڴ� */
	free(x);	
} 


void print()
{
	printf("...............�߾���ģ��(By STY)...............\n");
	printf("�߾��ȼӷ����1��\n");
	printf("�߾��ȼ������2��\n");
	printf("�߾��ȳ˷�(��)���3��\n");
	printf("�߾��ȳ˷�(��)���4��\n");
	printf("�߾��ȳ���(��)���5��\n");
	printf("�߾��ȳ���(��)���6��\n");
	printf("�߾��Ƚ׳����7��\n");
	printf("�˳��밴��Ctrl+Z��(�ڼ�����)�������س���ллʹ�ã�\n");
	printf("�����룺��1~7��\n");
}

void print_jia()
{
	printf("\n��ѡ���ˣ��߾��ȼӷ�\n"); 
	printf("�������������֣�\n");
	printf("���֣�\n");
	scanf("%s%s",s,ss);
	jia();     //���ø߾��ȼӷ����� 
}

void print_jian()
{
	printf("\n��ѡ���ˣ��߾��ȼ���\n"); 
	printf("�������������֣�\n");
	printf("���֣�\n");
	scanf("%s%s",s,ss);
	jian();    //���ø߾��ȼ�������
}

void print_cheng_di()
{
	printf("\n��ѡ���ˣ��߾��ȳ˷����ͣ�\n"); 
	printf("�������������֣�\n");
	printf("���֣�\n");
	scanf("%s%d",s,&d);
	cheng_di();    //���ø߾��ȳ˷����ͣ�����  
}

void print_cheng_gao()
{
	printf("\n��ѡ���ˣ��߾��ȳ˷����ߣ�\n"); 
	printf("�������������֣�\n");
	printf("���֣�\n");
	scanf("%s%s",s,ss);
	cheng_gao();   //���ø߾��ȳ˷����ߣ�����
}

void print_chu_di()
{
	printf("\n��ѡ���ˣ��߾��ȳ������ͣ�\n"); 
	printf("�������������֣�\n");
	printf("���֣�\n");
	scanf("%s%d",s,&d);
	chu_di();   //���ø߾��ȳ������ͣ����� 
}

void print_chu_gao()
{
	printf("\n��ѡ���ˣ��߾��ȳ������ߣ�\n"); 
	printf("�������������֣�\n");
	printf("���֣�\n");
	scanf("%s%s",s,ss); 
	if(Judge(ss)) 
		printf("0������������\n\n");
	else 
	{ 
		chu_gao();     //���ø߾��ȳ������ߣ�����
		if(!Judge(arr))
			printf("%s / %s=%s......%s\n\n",s,ss,cha,arr);
		else 
			printf("%s / %s=%s\n\n",s,ss,cha);  //���û�������Ͳ���� 
	}
} 

void print_jiecheng()
{
	printf("\n��ѡ���ˣ��߾��Ƚ׳�\n"); 
	printf("������һ�����֣�\n");
	printf("���������ñ𳬹�120000����Ȼ̫�����Ȳ��𣨿���Ҫ�㼸ʮ���ӣ�\n");
	printf("���֣�\n");
	scanf("%d",&d);
	jiecheng();   //���ø߾��Ƚ׳˺��� 
} 

/*-------------������--------------*/		
int main()   
{
	int choice,i;
//ԭ����print�еĴ�������дһ�飬���渴��һ�飬��д���˺��� 
	print();
	while(scanf("%d",&choice)!=EOF)    //��������ѭ�� 
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
//			printf("û����һ�����Ц�ˣ�\n");     

//����ע�͵���һ�κ�������switch-case�Ĵ�����һ����˼		
		switch(choice) 
		{
			case 1:print_jia();break;
			case 2:print_jian();break;
			case 3:print_cheng_di();break;
			case 4:print_cheng_gao();break;
			case 5:print_chu_di();break;
			case 6:print_chu_gao();break;
			case 7:print_jiecheng();break;
			default:printf("û����һ�����Ц�ˣ�\n");break;  
		}
		printf("\n\n");		//���� 
		print();
	}	
	return 0;
}