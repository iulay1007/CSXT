#include <stdio.h>
typedef int TElemType;						
typedef struct BiTNode							//二叉树二叉链表存储表示
{
	TElemType data;								//结点元素 
	struct BiTNode* lchild;						//左孩子指针 
	struct BiTNode* rchild;						//右孩子指针
	struct BiTNode* parent;
	int mark;//标记域 
}BiTNode;										//二叉树结点 
typedef BiTNode* BiTree;

void fx(BiTree T)
{
	BiTree p = T;
	
	while(p)
	{
		if(p->mark==0)
		{
			p->mark = 1;		
			if(p->lchild)
				p = p->lchild;
		}
		else if(p->mark==1)
		{
			p->mark = 2;
			if(p->rchild)	
				p = p->rchild;			
		}
		else				
		{
			p = p->parent;
		}
	}
}
