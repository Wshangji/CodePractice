#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1000000
using namespace std;
bool u[MAXN];        //ɸ��
int su[MAXN],num=0;       //������������

void eulerSieve(){
    memset(u,true,sizeof(u));       //��ʼ��
    int i;
    for(i=2; i<=MAXN; i++){         //˳�����������е�ÿ����
        if(u[i])
            su[++num]=i;
        for(int j=1; j<=num; j++){
            if(i*su[j]>MAXN)        //���i�뵱ǰ�����ĳ˻�����MAXN��������
                break;
            u[i*su[j]]=false;       //�����ı�����Ϊ��������ɸȥ
            if(i%su[j]==0)          //���su[j]��i����С�������������һ��i���ж�
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
