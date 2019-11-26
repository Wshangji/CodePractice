#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//创建结构体类型来表示链表节点
struct node{
    int date;           //储存数据
    struct node *next;  //指向下一节点
};

int main(){
    struct node *head,*p,*q,*t;
    int n,a;
    printf("输入数字总数：\t");
    scanf("%d",&n);
    head=NULL;          //将头指针设置为空
    printf("输入n个数：\t");
    for(int i=1; i<=n; i++){
        scanf("%d",&a);
        //动态申请一个空间，用来存放一个节点，并用临时指针p指向这个节点
        p=(struct node *)malloc(sizeof(struct node));
        p->date=a;          //将数储存在date域中
        p->next=NULL;       //将后继指针设为空
        if(head == NULL)
            head=p;         //如果这是第一个节点，则将头指针指向当前节点
        else
            q->next=p;      //如果不为第一个节点，那么上一指针指向
        q=p;                //指针q指向当前节点
    }

    //插入一个节点
    printf("插入一个数：\t");
    scanf("%d",&a);
    t=head;
    while(t!=NULL){
            if(t->next==NULL || t->next->date >a){
                p=(struct node *)malloc(sizeof(struct node));   //申请一个节点
                p->date=a;
                p->next=t->next;        //新增指针的后继指针指向当前后继指针指向的结点
                t->next=p;              //当前指针的后继指针指向当前指针
                break;
            }
            t=t->next;
        }
    //顺序输出链表
    t=head;
    while(t != NULL){
        printf("%d ",t->date);
        t=t->next;
    }
    return 0;
}
