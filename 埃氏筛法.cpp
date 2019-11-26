#include <iostream>
#include <cmath>
#include <cstdio>
#define MAXN 1000000
using namespace std;
bool u[MAXN];
int su[MAXN],num=0;

void prepare(){
    int i,j;
    for(int i=2; i<=MAXN; i++)
        u[i]=true;
    for(i=2; i<=MAXN; i++)
        if(u[i]){
            for(j=2; i*j<=MAXN; j++)
                u[i*j]=false;
        }
    for(i=2; i<=MAXN; i++)
        if(u[i])
            su[++num]=i;
}

int main(){
    prepare();
    int n;
    cin>>n;
    for(int i=1; i<=num; i++)
        cout<<su[i]<<" ";
    return 0;
}
