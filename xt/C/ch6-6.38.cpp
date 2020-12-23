#include <stdio.h>
#include <malloc.h>
#define SElemType int
#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 2 /* �洢�ռ�������� */
typedef struct SqStack
 {
   SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   SElemType *top; /* ջ��ָ�� */
   int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
 }SqStack;
typedef struct BiTNode
 {
   int data;
   struct BiTNode *lchild,*rchild; /* ���Һ���ָ�� */
 }BiTNode,*BiTree;
int InitBiTree(BiTree *T)
 { /* �������: ����ն�����T */
   *T=NULL;
   return 1;
 }
 int BiTreeEmpty(BiTree T)
 { /* ��ʼ����: ������T���� */
   /* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
   if(T)
     return 0;
   else
     return 1;
 }
 
 int InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     return -1; /* �洢����ʧ�� */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 1;
 }
 int GetTop(SqStack S,SElemType *e)
 { /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 1;
   }
   else
     return 0;
 }
 int Push(SqStack *S,SElemType e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
      return -1; /* �洢����ʧ�� */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 1;
 }
 
 int Pop(SqStack *S,SElemType *e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if((*S).top==(*S).base)
     return 0;
   *e=*--(*S).top;
   return 1;
 }
 
  int StackEmpty(SqStack S)
 { /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
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
	int StackMark[100] = {};							//ģ��ջ�����ø������ʱ�� 
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
			
		while(!p && !StackEmpty(S))			//pΪ�յ�ջ��Ϊ�� 
		{
			GetTop(S, &p->data);
			
			if(StackMark[k]==1)				//�ѷ��ʹ�һ�Σ���ǰ�ǵڶ��η��� 
			{
				StackMark[k] = 2;				
				p = p->rchild;
			}
			else							//�ѷ��ʹ����Σ���ǰ�ǵ����η��� 
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
