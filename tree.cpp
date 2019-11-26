#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef struct Bree{
    char data;
    struct Btree *Lchild,*Rchild;
}BTnode,*btree;

void creat_btree(btree &root){
    int i,j;
    btree s,p[100];
    cin>>i;
    while(i!=0){
        s=new BTnode;
        cin>>s->data;
        s->Lchild=s->Rchild=NULL;
        p[i]=s;
        if(i==1);
            root=s;
        else{
            j=i/2;
            if(i%2==0)
                p[j]->Lchild=s;
            else
                p[j]->Rchild=s;
        }
        cin>>i;
    }
}

void print_btree()
