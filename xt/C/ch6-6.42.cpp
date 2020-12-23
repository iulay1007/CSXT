#include <stdio.h>
typedef struct BiTNode
 {
   int data;
   struct BiTNode *lchild,*rchild; /* ×óÓÒº¢×ÓÖ¸Õë */
 }BiTNode,*BiTree;
int fx(BiTree T)
{
	int count = 0;
	
	if(T)
	{
		if(T->lchild==NULL && T->rchild==NULL)
			count++;
		else
		{
			count += fx(T->lchild);
			count += fx(T->rchild);
		}	
	}
	
	return count;	 
}
