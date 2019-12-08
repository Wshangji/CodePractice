#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
//结构体定义链表节点
struct Listnode{
    int data;           //数据域
    Listnode *next;     //指针域
};

struct Listnode* Creat_Listnode();                              //创建链表
int Length_Listnode(struct Listnode *head);                     //获取链表长度
void Sort_Listnode(struct Listnode *head);                      //链表排序
struct Listnode* Insert_Listnode(struct Listnode *head, int x); //链表节点插入
struct Listnode* Delete_Listnode(struct Listnode *head, int x); //链表节点删除
void Print_Listnode(struct Listnode *head);                     //打印链表

int main(){
    int x;
    struct Listnode *head;
    printf("构建单向链表(直到输入的数小于0):\n");
    head = Creat_Listnode();
    Print_Listnode(head);
    printf("\n");
    printf("链表排序:\n");
    Sort_Listnode(head);
    Print_Listnode(head);
    printf("\n");
    printf("插入节点:\n请输入插入数字\t");
    scanf("%d",&x);
    Insert_Listnode(head, x);
    Print_Listnode(head);
    printf("\n");
    printf("删除节点：\n请输入删除数字\t");
    scanf("%d",&x);
    Delete_Listnode(head, x);
    Print_Listnode(head);
    printf("\n");
    return 0;
}
//尾插法构建单向链表
struct Listnode* Creat_Listnode(){
    struct Listnode *head,*p,*q;
    head = NULL;
    int x;
    while(scanf("%d",&x) && x>0){
        p = (struct Listnode *)malloc(sizeof(struct Listnode));
        p->data = x;
        p->next = NULL;
        if(head == NULL)
            head = p;
        else
            q->next = p;
        q = p;
    }
    return head;
}
//获取链表长度
int Length_Listnode(struct Listnode *head){
    int len = 0;
    struct Listnode *t;
    t = head;
    while(t != NULL){
        len++;
        t = t->next;
    }
    return len;
}
//链表排序
void Sort_Listnode(struct Listnode *head){
    int len = Length_Listnode(head);
    if (len == 0)
        return;
    struct Listnode *p = head;
    int tmp;
    for (int i = 0; i<len-1; i++){
        p = head;
        for (int j = 0; j < len-i-1; j++){
            if (p->data > p->next->data){
                tmp = p->data;
                p->data = p->next->data;
                p->next->data = tmp;
            }
            p = p->next;
        }
    }
}
//顺序插入节点
struct Listnode* Insert_Listnode(struct Listnode *head, int x){
    struct Listnode *t,*p;
    t = head;
    p = (struct Listnode*)malloc(sizeof(struct Listnode));
    if(x < head->data){
        p->data = head->data;
        p->next = head->next;
        head->data = x;
        head->next = p;
    }
    else{                   //非头节点插入
        while(t!=NULL){
            if(t->next==NULL || t->next->data >x){
                p->data=x;
                p->next=t->next;        //新增指针的后继指针指向当前后继指针指向的结点
                t->next=p;              //当前指针的后继指针指向当前指针
                break;
            }
            t=t->next;
        }
    }
    return head;
}
//删除链表节点
struct Listnode* Delete_Listnode(struct Listnode *head, int x){
    struct Listnode *t,*p;
    t=head;
    if(head->data == x){       //头节点删除
        p = head->next;
        head->data = head->next->data;
        head->next = head->next->next;
        free(p);
    }
    else{                       //非头节点删除
        while(t != NULL){
            if(t->next->data == x){
                p = t->next;
                t->next = p->next;
               free(p);
                break;
            }
            t = t->next;
        }
    }
    return head;
}
//打印链表
void Print_Listnode(struct Listnode *head){
    Listnode *t;
    t = head;
    if(t == NULL)
        printf("!链表为空!");
    else{
        while(t != NULL){
            printf("%d ",t->data);
            t = t->next;
        }
    }
}
