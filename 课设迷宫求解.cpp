#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define MAXSIZE 50
#define Status int
#define N 10         //迷宫的边长 
#define MAZE_IN_X 1  //迷宫入口坐标    
#define MAZE_IN_Y 0 
int i=2;
//迷宫构成 
int a[N][N] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 0, 0, 0, 1, 0, 0, 1, 0, 1, 1},
		{ 1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
		{ 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
		{ 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},
		{ 1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
		{ 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
		{ 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
		{ 1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
typedef struct index            //迷宫内每个点的坐标
{
	int row;
	int col;
}index;

typedef index SElemType;

typedef struct maze          //迷宫
{
	int mz[N][N];
	index entry;               //入口点
}maze;

typedef struct SqStack         //顺序栈 
{
	SElemType *base; 
	SElemType *top;         
	int stacksize;            //最大容量
}SqStack;

//初始化迷宫 
void mazeinit(maze &M,int a[N][N])
{
	
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			M.mz[i][j] = a[i][j];
		}
	}
	M.entry.row = MAZE_IN_X;
	M.entry.col = MAZE_IN_Y;
}

//输出迷宫 
void mazeprint(maze &M)
{
	printf("迷宫为：\n\n");
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			printf("%d  ", (M.mz)[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//栈的初始化
Status InitStack(SqStack &S)
{
	
	S.base = (SElemType*)malloc(sizeof(SElemType)*MAXSIZE);
	if (!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//入栈
Status Push(SqStack &S, SElemType e)
{
	
	if (S.top-S.base==S.stacksize)return ERROR;
	*S.top++=e;
	return OK;
}

//出栈，不取出栈元素 
Status Pop(SqStack &S)
{
	if (S.top==S.base)return ERROR;
	--S.top;
	return OK; 
}
//判断栈是否为空
Status StackEmpty(SqStack S)
{
	if (S.top==S.base)return TRUE;
	else return ERROR;
}

//判断是否能入栈
Status pushable(index cur, maze &M,int i)
{
	if (cur.row >= 0 && cur.row < N&&cur.col >= 0 && cur.col < N &&M.mz[cur.row][cur.col] ==0||M.mz[cur.row][cur.col]-1>i )  
	{
		return TRUE;
	}
	return ERROR;
}

//标记已经访问过的点 
void mark(index cur, maze &M,int i)
{
	M.mz[cur.row][cur.col] = i;
}

//检查是否到达迷宫出口
Status check_exit(index cur, maze &M)
{
	if ((cur.row == 0) || (cur.row == N - 1) || (cur.col == 0) || (cur.col == N - 1))
	{
		if ((cur.row) != ((M.entry).row) && (cur.col) != ((M.entry).col))
		{
			return OK;
		}

	}
	return ERROR;
}
//输出走出迷宫的路径 
void print_stack(SqStack &s)
{
	printf("走出迷宫的路径长度为：%d，路径为:\n\n",s.top-s.base);
	for (int i = 0;i < s.top-s.base-1;i++)
	{
		printf("[%d %d]->", (s.base+i)->row, (s.base+i)->col);
	}
	printf("[%d %d]\n\n", (s.top-1)->row, (s.top-1)->col);
}
//查找走出迷宫的路径 
Status found_path(maze &M, index cur, SqStack &s,int i)
{
	if (pushable(cur, M,i) == 1)
	{
		mark(cur, M,i);
		i++;
		Push(s, cur);
	}
	else
	{
		return OK;
	}
	if (check_exit(cur, M) == OK)
	{
		print_stack(s);
		return OK;
	}
	index up = cur;
	up.row -= 1;
	found_path(M, up, s,i);
	index right = cur;
	right.col += 1;
	found_path(M, right, s,i);
	index down = cur;
	down.row += 1;
	found_path(M, down, s,i);
	index left = cur;
	left.col -= 1;
	found_path(M, left, s,i);
	Pop(s);
	return OK;
}


int main()
{
	maze M;
	SqStack path;
	InitStack(path);
	mazeinit(M,a);
	mazeprint(M);
	found_path(M, M.entry, path,i);
	if(StackEmpty(path)){
		printf("该迷宫没有出口！"); 
	} 
	return 0;
}

