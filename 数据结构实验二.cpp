
//ͷ�ļ�

#include "stdlib.h"
#include<stdio.h>

//Ԥ���峣��

//#define NULL 0

 
//������Ķ���

typedef struct LNode{

    int data;

    struct LNode *next;

}LNode,*LinkList;

//������Ĵ���

void Create_List(LinkList &L)

{

    int data;

    LinkList p,q;

    L=(LinkList)malloc(sizeof(LNode));

    L->next=NULL;
    q=L;
 
    scanf("%d",&data);

    while(data!=0)

    {
       p=(LinkList)malloc(sizeof(LNode));

       p->data=data;
       
       p->next=q->next;

       q->next=p;

 

       q=p;

       scanf("%d",&data);

    }

}

//������ı���

 void TranverseList(LinkList L)

 {

     LinkList p;

 

     p=L->next;

     if (p==NULL)

     {

        printf("nil\n");

        return;

     }

     while(p!=NULL)

     {

        printf("%d ",p->data);

        p=p->next;

     }

     printf("\n");

 }
 void ListInsert(LinkList &L,int i,int data){
 	LinkList p=L;
 	int j=0;
 	while(p&&(j<i-1))
 		{
		 p=p->next;
 		j++;
		 }
		LinkList s = (LinkList)malloc(sizeof(LNode));
		 s->data=data;
		 s->next=p->next;
		 p->next=s;
		 return;
	 
 }
 void ListDelete(LinkList &L,int i){
 	int j=0;
	 LinkList p=L;
 	while(p&&j<i-1){
 		j++;
 		p=p->next;
	 }
	 LinkList s;
	  s = (LinkList )malloc(sizeof(LNode));
	// s = (LNode* )malloc(sizeof(LNode));
	 s=p->next;
	 p->next=s->next;
	 free(s);
	 return;
 } 
 int main(){
 	LinkList L;
 	Create_List(L);
 	ListInsert(L,1,2);
 	printf("�ڵ�һ���ڵ����2�Ľ��Ϊ��");
	 TranverseList(L);
 	ListDelete(L,2);
 	printf("ɾ���ڶ����ڵ�Ľ��Ϊ��"); 
 	 TranverseList(L);
 }


