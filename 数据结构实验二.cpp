
//头文件

#include "stdlib.h"
#include<stdio.h>

//预定义常量

//#define NULL 0

 
//单链表的定义

typedef struct LNode{

    int data;

    struct LNode *next;

}LNode,*LinkList;

//单链表的创建

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

//单链表的遍历

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
 	printf("在第一个节点插入2的结果为：");
	 TranverseList(L);
 	ListDelete(L,2);
 	printf("删除第二个节点的结果为："); 
 	 TranverseList(L);
 }


