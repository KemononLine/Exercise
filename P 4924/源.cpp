#include <iostream>
#include <cstdio>
using namespace std;
int g[510][510], tot, f[510][510];//f����䵱��ʱ���� 
int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			g[i][j] = ++tot;
	for (int i = 1;i <= m;i++) {
		int a, b, r, opt;
		scanf_s("%d %d %d %d", &a, &b, &r, &opt);//����ķ������������һ�������Ե� 
		if (opt == 0) {//��i�е�j�� ��ɵ�����i�е�j�� ˳ʱ�� 
			for (int i = a - r;i <= a + r;i++)
				for (int j = b - r;j <= b + r;j++)
					f[a - b + j][a + b - i] = g[i][j];
			for (int i = a - r;i <= a + r;i++)
				for (int j = b - r;j <= b + r;j++)
					g[i][j] = f[i][j];
		}
		else { //��i�е�j�� ��ɵ�i�е�����j�� ��ʱ�� 
			for (int i = a - r;i <= a + r;i++)
				for (int j = b - r;j <= b + r;j++)
					f[a + b - j][b - a + i] = g[i][j];
			for (int i = a - r;i <= a + r;i++)
				for (int j = b - r;j <= b + r;j++)
					g[i][j] = f[i][j];
		}
	}
	for (int i = 1;i <= n;i++) {//�������� 
		for (int j = 1;j <= n;j++)
			printf("%d ", g[i][j]);
		printf("\n");
	}
	return 0;
}