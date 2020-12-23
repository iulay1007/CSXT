#include <stdio.h>
typedef struct BiTNode
 {
   int data;
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
 }BiTNode,*BiTree;
int fx(BiTree T, int *e, int *order, int k)	//order用来计数 
{
	if(T)
	{
		(*order)++;
		
		if(*order==k)
		{
			*e = T->data;		
			return 1;				
		}
		else
		{		
			if(fx(T->lchild, e, order, k))
				return 1;
			if(fx(T->rchild, e, order, k))
				return 1;
		}
	}
	
	return 0;
}
