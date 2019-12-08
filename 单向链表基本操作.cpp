#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
//�ṹ�嶨������ڵ�
struct Listnode{
    int data;           //������
    Listnode *next;     //ָ����
};

struct Listnode* Creat_Listnode();                              //��������
int Length_Listnode(struct Listnode *head);                     //��ȡ������
void Sort_Listnode(struct Listnode *head);                      //��������
struct Listnode* Insert_Listnode(struct Listnode *head, int x); //����ڵ����
struct Listnode* Delete_Listnode(struct Listnode *head, int x); //����ڵ�ɾ��
void Print_Listnode(struct Listnode *head);                     //��ӡ����

int main(){
    int x;
    struct Listnode *head;
    printf("������������(ֱ���������С��0):\n");
    head = Creat_Listnode();
    Print_Listnode(head);
    printf("\n");
    printf("��������:\n");
    Sort_Listnode(head);
    Print_Listnode(head);
    printf("\n");
    printf("����ڵ�:\n�������������\t");
    scanf("%d",&x);
    Insert_Listnode(head, x);
    Print_Listnode(head);
    printf("\n");
    printf("ɾ���ڵ㣺\n������ɾ������\t");
    scanf("%d",&x);
    Delete_Listnode(head, x);
    Print_Listnode(head);
    printf("\n");
    return 0;
}
//β�巨������������
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
//��ȡ������
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
//��������
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
//˳�����ڵ�
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
    else{                   //��ͷ�ڵ����
        while(t!=NULL){
            if(t->next==NULL || t->next->data >x){
                p->data=x;
                p->next=t->next;        //����ָ��ĺ��ָ��ָ��ǰ���ָ��ָ��Ľ��
                t->next=p;              //��ǰָ��ĺ��ָ��ָ��ǰָ��
                break;
            }
            t=t->next;
        }
    }
    return head;
}
//ɾ������ڵ�
struct Listnode* Delete_Listnode(struct Listnode *head, int x){
    struct Listnode *t,*p;
    t=head;
    if(head->data == x){       //ͷ�ڵ�ɾ��
        p = head->next;
        head->data = head->next->data;
        head->next = head->next->next;
        free(p);
    }
    else{                       //��ͷ�ڵ�ɾ��
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
//��ӡ����
void Print_Listnode(struct Listnode *head){
    Listnode *t;
    t = head;
    if(t == NULL)
        printf("!����Ϊ��!");
    else{
        while(t != NULL){
            printf("%d ",t->data);
            t = t->next;
        }
    }
}
