 #include <stdio.h>  
    #include <malloc.h>   //malloc   
    #include <math.h>     //����overflow  
    #define S_SIZE 100   //ջ�Ŀռ��С    
    typedef struct SqStack{  
     int top;  //ջ��  
     int maxtop;   //ջ���Ĵ洢�ռ�  
     int *stack;  
    }SqStack;  
    
  //��ʼ����ջ   
    void InitStack(SqStack &S)  
    {
		S.stack=(int *)malloc(S_SIZE*sizeof(int));  //��̬����һά���� 
        S.maxtop=S_SIZE;  
        S.top=-1;
    }  
 
//�жϿ�ջ
    int StackEmpty(SqStack &S)  
    {  
       if(S.top==-1)  
           return 1;  
       else  
           return 0;  
    }   
//�ж�ջ��
    int  StackFull(SqStack &S)
    {
       if(S.top==S.maxtop)  
           return 1;  
       else  
           return 0;  
	}
 
    //��ջ
	void push(SqStack &S,int x)  
    { 
      if(StackFull(S))
      	printf("overflow\n");
 	  S.stack[++S.top]=x; 
    }  
    //��ջ
	int pop(SqStack &S)  
    {
      int x;
   	  if(StackEmpty(S))
      	 printf("underflow\n");
      x=S.stack[S.top];	
      S.top--;
      return x;
    } 
	//����ת������
	void convert(SqStack &S,int N,int n)  
    {  
      int i,x; 
      do   
      {
	  	push(S,N%n);  
    	N/=n;  
      } while (N!=0);   
      
      while(!StackEmpty(S))  
      { 
	   	x=pop(S);
	    if(x>9) //ʮ������ʱ�����ĸ  
        {
			x=x+55;  
       		printf("%c",x);
		}  
        else  
      	    printf("%d",x);  
      }  
      printf("\n");  
    }  
    //���ջ
   void StackClear(SqStack &S)
   {
      S.top=-1;
   }
   int main()  
    { 
  		int n,N;//Ҫת���ɵĽ�������Ҫת������ 
		SqStack s; 
		scanf("%d%d",&n,&N) ;
    	        InitStack(s);
   		printf("%dת��Ϊ%d���ƺ�Ϊ:\n",n,N);  
   		convert(s,n,N);    
                StackClear(s);
                return 0;
 }

