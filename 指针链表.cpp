#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//�����ṹ����������ʾ����ڵ�
struct node{
    int date;           //��������
    struct node *next;  //ָ����һ�ڵ�
};

int main(){
    struct node *head,*p,*q,*t;
    int n,a;
    printf("��������������\t");
    scanf("%d",&n);
    head=NULL;          //��ͷָ������Ϊ��
    printf("����n������\t");
    for(int i=1; i<=n; i++){
        scanf("%d",&a);
        //��̬����һ���ռ䣬�������һ���ڵ㣬������ʱָ��pָ������ڵ�
        p=(struct node *)malloc(sizeof(struct node));
        p->date=a;          //����������date����
        p->next=NULL;       //�����ָ����Ϊ��
        if(head == NULL)
            head=p;         //������ǵ�һ���ڵ㣬��ͷָ��ָ��ǰ�ڵ�
        else
            q->next=p;      //�����Ϊ��һ���ڵ㣬��ô��һָ��ָ��
        q=p;                //ָ��qָ��ǰ�ڵ�
    }

    //����һ���ڵ�
    printf("����һ������\t");
    scanf("%d",&a);
    t=head;
    while(t!=NULL){
            if(t->next==NULL || t->next->date >a){
                p=(struct node *)malloc(sizeof(struct node));   //����һ���ڵ�
                p->date=a;
                p->next=t->next;        //����ָ��ĺ��ָ��ָ��ǰ���ָ��ָ��Ľ��
                t->next=p;              //��ǰָ��ĺ��ָ��ָ��ǰָ��
                break;
            }
            t=t->next;
        }
    //˳���������
    t=head;
    while(t != NULL){
        printf("%d ",t->date);
        t=t->next;
    }
    return 0;
}
