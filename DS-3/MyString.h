#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
using namespace std;

int Next[10004] = {-1,0};

void GetNext(char* t);
void KMPpro(char* s, char* p, char* t);

void GetNext(char* t)
{
	int j = 0;
	int k = -1;
	int len = strlen(t);
	while (j < len - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			Next[j] = k;
		}
		else
			k = Next[k];
	}
}

void KMPpro(char* s, char* p, char* t)
{
	int i = 0, j = 0;
	int lens = strlen(s);
	int lent = strlen(t);
	int lenp = strlen(p);
	while (s[i]!='\0')
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Next[j];
		}
		if (j >= lent)
		{
			int ii = i - lent;
			int temp;
			if (lenp >= lent)
			{
				int gap = lenp - lent;
				if(i<lens)
				{
					for (temp = lens - 1;temp >= i;temp--)
					{
						s[temp + gap] = s[temp];
					}
					lens = lens + gap;
					s[lens] = '\0';
					for (int k = 0;k < lenp;k++)
					{
						s[ii] = p[k];
						ii++;
					}
				}
				else
				{
					for (int k = 0;k < lenp;k++)
					{
						s[ii] = p[k];
						ii++;
					}
					lens = lens + gap;
					s[ii] = '\0';
				}
			}
			else
			{
				int gap = lent - lenp;
				if (i < lens)
				{
					for (int l=i;l<lens;l++)
					{
						s[l- gap] = s[l];
					}
					lens = lens - gap;
					for (int k = 0;k < lenp;k++)
					{
						s[ii] = p[k];
						ii++;
					}
				}
				else
				{
					for (int k = 0;k < lenp;k++)
					{
						s[ii] = p[k];
						ii++;
					}
					lens = lens - gap;
					s[ii] = '\0';
				}
			}
		}
	}
}

#endif