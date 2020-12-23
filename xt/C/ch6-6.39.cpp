#include <stdio.h>
typedef int TElemType;						
typedef struct BiTNode							//��������������洢��ʾ
{
	TElemType data;								//���Ԫ�� 
	struct BiTNode* lchild;						//����ָ�� 
	struct BiTNode* rchild;						//�Һ���ָ��
	struct BiTNode* parent;
	int mark;//����� 
}BiTNode;										//��������� 
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
