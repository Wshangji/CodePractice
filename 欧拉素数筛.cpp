#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1000000
using namespace std;
bool u[MAXN];        //筛子
int su[MAXN],num=0;       //创建素数表及表长

void eulerSieve(){
    memset(u,true,sizeof(u));       //初始化
    int i;
    for(i=2; i<=MAXN; i++){         //顺序分析区间表中的每个数
        if(u[i])
            su[++num]=i;
        for(int j=1; j<=num; j++){
            if(i*su[j]>MAXN)        //如果i与当前素数的乘积大于MAXN，则跳过
                break;
            u[i*su[j]]=false;       //素数的倍数必为非素数，筛去
            if(i%su[j]==0)          //如果su[j]是i的最小素数，则进行下一个i的判断
                break;
        }
    }
}

int main(){
    eulerSieve();
    for(int i=1; i<=num; i++)
        printf("%d ",su[i]);
    return 0;
}
