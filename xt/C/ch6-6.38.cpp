#include <stdio.h>
#include <malloc.h>
#define SElemType int
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack
 {
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack;
typedef struct BiTNode
 {
   int data;
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
 }BiTNode,*BiTree;
int InitBiTree(BiTree *T)
 { /* 操作结果: 构造空二叉树T */
   *T=NULL;
   return 1;
 }
 int BiTreeEmpty(BiTree T)
 { /* 初始条件: 二叉树T存在 */
   /* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
   if(T)
     return 0;
   else
     return 1;
 }
 
 int InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     return -1; /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 1;
 }
 int GetTop(SqStack S,SElemType *e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 1;
   }
   else
     return 0;
 }
 int Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
      return -1; /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 1;
 }
 
 int Pop(SqStack *S,SElemType *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
   if((*S).top==(*S).base)
     return 0;
   *e=*--(*S).top;
   return 1;
 }
 
  int StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return 1;
   else
     return 0;
 }
 
void order(BiTree T)
{
	SqStack S;
	BiTree p;
	int e;
	int StackMark[100] = {};							//模拟栈，设置各结点访问标记 
	int k;
	InitStack(&S);
	p = T;
	k = -1;
		
	while(1)
	{
		while(p)
		{
			Push(&S, p->data);
			k++;
			StackMark[k] = 1;
			p = p->lchild;
		}
			
		while(!p && !StackEmpty(S))			//p为空但栈不为空 
		{
			GetTop(S, &p->data);
			
			if(StackMark[k]==1)				//已访问过一次，当前是第二次访问 
			{
				StackMark[k] = 2;				
				p = p->rchild;
			}
			else							//已访问过两次，当前是第三次访问 
			{
				printf("%c ", p->data);
				Pop(&S, &e);
				StackMark[k] = 0;
				k--;
				p = NULL;
			}
		}
		
		if(StackEmpty(S))
			break;
	}		
}
