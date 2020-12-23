#include <stdio.h>
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

int dfs(BiTree B1, BiTree B2)
{
	if(BiTreeEmpty(B1) && BiTreeEmpty(B2))			//都为空树 
		return 1;
	else
	{
		if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2))	//都不为空树 
		{
			if(dfs(B1->lchild, B2->lchild) && dfs(B1->rchild, B2->rchild))	//判断左右子树 
				return 1;	
		}
	}
	
	return 0;
}
