#include <stdio.h>
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

int dfs(BiTree B1, BiTree B2)
{
	if(BiTreeEmpty(B1) && BiTreeEmpty(B2))			//��Ϊ���� 
		return 1;
	else
	{
		if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2))	//����Ϊ���� 
		{
			if(dfs(B1->lchild, B2->lchild) && dfs(B1->rchild, B2->rchild))	//�ж��������� 
				return 1;	
		}
	}
	
	return 0;
}
