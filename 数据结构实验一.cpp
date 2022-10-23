#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define INCREM 10
#define INIT_SIZE 100
#define OK 1
#define ERROR 0

typedef int ElemType;

typedef struct Sqlist
{
	ElemType *slist;
	int length;
    int listsize;
}Sqlist;

int InitList(Sqlist *L)
{
    L->slist=(ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
    if(!L->slist) return ERROR;
    L->length = 0;
    L->listsize = INIT_SIZE;
    return OK;
}

int ListInsert(Sqlist *L,ElemType e)    // 插入数据 
{

	if(!L->length)
	{
		L->length++;
	
		L->slist[0] = e;
	}
	int z=0;
	for(int j=L->length; j>=0;j--)
	{
   	    if(e==L->slist[j-1])
		{
	    	break;
   		}
	    else if(e>L->slist[j-1])
		{
   			z=j;
   			for(int j=L->length;j>=z+1;j--)
			{
		   		L->slist[j]=L->slist[j-1];
		   	}
		   	L->slist[z]=e;
   			L->length++;
   			break;
   		}
   	}

}

int main()
{
	int n,r,a;
	Sqlist L;
		printf("请输入递增有序顺序表的元素个数：");
	scanf("%d",&n);
	if(n <= 100)
	{
		InitList(&L);
	
    	L.length=n;
    		printf("请输入递增有序顺序表：\n");
    	for(r = 0; r < L.length; r++)
    	{
    	    scanf("%d",&L.slist[r]);
   		}
   			printf("请输入要插入数据：");
    	scanf("%d",&a);
    	
    	ListInsert(&L,a);
    	for(r = 0; r < L.length; r++)
			printf("%d ",L.slist[r]);
	}
	else
	{
		printf("error");
	}
    return 0;
}

