#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct node(){
    int data;
    struct node *befor;
    struct node *last;
}

void pre_node(node *head, int n){   //构建双向链表
    node *p,*q;
    int a;
    head = NULL;
    for(inti=0; i<n; i++){
        scanf("%d",a);
        p=(struct node *)malloc(sizeof(struct node));
        p->date = a;
        p->last = NULL;
        if(head == NULL){
            head = p;
            p->before = NULL;
        }
        else{
            q->next = p;
            p->before = q;
        }
        q=p;
    }
}

void pre_print(node *head){
    struct node *t;
    t = head;
    while(t != NULL){
        printf("%d ",t->data)
        t = t->next;
    }
}

int main(){
    struct node *head;
    int n;
    cin>>n;
    pre_node(*head, n);
    pre_print(*head);
    return 0;
}
