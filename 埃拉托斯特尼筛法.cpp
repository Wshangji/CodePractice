#include <iostream>
#include <cmath>
#include <cstdio>
#define MAXN 1000000
using namespace std;
bool u[MAXN];			//筛子
int su[MAXN], num = 0;	//素数表，表长度

void prepare() {		//用筛选法构造素数表
	int i, j;
	for (int i = 2; i < MAXN; i++)		//进行标记初始化
		u[i] = true;
	for (i = 2; i < MAXN; i++)			//顺序分析
		if (u[i]) {						//将j与当前素数的乘积筛去
			for (j = 2; i * j < MAXN; j++)
				u[i * j] = false;
		}
	for (i = 2; i < MAXN; i++)			//晒出的素数填入素数表中
		if (u[i])
			su[++num] = i;
}

int main() {
	prepare();
	for (int i = 1; i <= num; i++)
		cout << su[i] << " ";
	return 0;
}
