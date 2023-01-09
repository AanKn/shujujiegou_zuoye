 #include <stdio.h>  
    #include <malloc.h>   //malloc   
    #include <math.h>     //含有overflow  
    #define S_SIZE 100   //栈的空间大小    
    typedef struct SqStack{  
     int top;  //栈顶  
     int maxtop;   //栈最大的存储空间  
     int *stack;  
    }SqStack;  
    
  //初始化空栈   
    void InitStack(SqStack &S)  
    {
		S.stack=(int *)malloc(S_SIZE*sizeof(int));  //动态申请一维数组 
        S.maxtop=S_SIZE;  
        S.top=-1;
    }  
 
//判断空栈
    int StackEmpty(SqStack &S)  
    {  
       if(S.top==-1)  
           return 1;  
       else  
           return 0;  
    }   
//判断栈满
    int  StackFull(SqStack &S)
    {
       if(S.top==S.maxtop)  
           return 1;  
       else  
           return 0;  
	}
 
    //进栈
	void push(SqStack &S,int x)  
    { 
      if(StackFull(S))
      	printf("overflow\n");
 	  S.stack[++S.top]=x; 
    }  
    //出栈
	int pop(SqStack &S)  
    {
      int x;
   	  if(StackEmpty(S))
      	 printf("underflow\n");
      x=S.stack[S.top];	
      S.top--;
      return x;
    } 
	//进制转化函数
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
	    if(x>9) //十六进制时输出字母  
        {
			x=x+55;  
       		printf("%c",x);
		}  
        else  
      	    printf("%d",x);  
      }  
      printf("\n");  
    }  
    //清空栈
   void StackClear(SqStack &S)
   {
      S.top=-1;
   }
   int main()  
    { 
  		int n,N;//要转换成的进制数和要转换的数 
		SqStack s; 
		scanf("%d%d",&n,&N) ;
    	        InitStack(s);
   		printf("%d转换为%d进制后为:\n",n,N);  
   		convert(s,n,N);    
                StackClear(s);
                return 0;
 }

