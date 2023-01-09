#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define MAXSIZE 50
#define Status int
#define N 10         //�Թ��ı߳� 
#define MAZE_IN_X 1  //�Թ��������    
#define MAZE_IN_Y 0 
int i=2;
//�Թ����� 
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
typedef struct index            //�Թ���ÿ���������
{
	int row;
	int col;
}index;

typedef index SElemType;

typedef struct maze          //�Թ�
{
	int mz[N][N];
	index entry;               //��ڵ�
}maze;

typedef struct SqStack         //˳��ջ 
{
	SElemType *base; 
	SElemType *top;         
	int stacksize;            //�������
}SqStack;

//��ʼ���Թ� 
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

//����Թ� 
void mazeprint(maze &M)
{
	printf("�Թ�Ϊ��\n\n");
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
//ջ�ĳ�ʼ��
Status InitStack(SqStack &S)
{
	
	S.base = (SElemType*)malloc(sizeof(SElemType)*MAXSIZE);
	if (!S.base)exit(OVERFLOW);
	S.top=S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//��ջ
Status Push(SqStack &S, SElemType e)
{
	
	if (S.top-S.base==S.stacksize)return ERROR;
	*S.top++=e;
	return OK;
}

//��ջ����ȡ��ջԪ�� 
Status Pop(SqStack &S)
{
	if (S.top==S.base)return ERROR;
	--S.top;
	return OK; 
}
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
	if (S.top==S.base)return TRUE;
	else return ERROR;
}

//�ж��Ƿ�����ջ
Status pushable(index cur, maze &M,int i)
{
	if (cur.row >= 0 && cur.row < N&&cur.col >= 0 && cur.col < N &&M.mz[cur.row][cur.col] ==0||M.mz[cur.row][cur.col]-1>i )  
	{
		return TRUE;
	}
	return ERROR;
}

//����Ѿ����ʹ��ĵ� 
void mark(index cur, maze &M,int i)
{
	M.mz[cur.row][cur.col] = i;
}

//����Ƿ񵽴��Թ�����
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
//����߳��Թ���·�� 
void print_stack(SqStack &s)
{
	printf("�߳��Թ���·������Ϊ��%d��·��Ϊ:\n\n",s.top-s.base);
	for (int i = 0;i < s.top-s.base-1;i++)
	{
		printf("[%d %d]->", (s.base+i)->row, (s.base+i)->col);
	}
	printf("[%d %d]\n\n", (s.top-1)->row, (s.top-1)->col);
}
//�����߳��Թ���·�� 
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
		printf("���Թ�û�г��ڣ�"); 
	} 
	return 0;
}

