typedef int TElemType;						
typedef struct BiTNode							//��������������洢��ʾ
{
	int data;								//���Ԫ�� 
	struct BiTNode* lchild;						//����ָ�� 
	struct BiTNode* rchild;						//�Һ���ָ��
	struct BiTNode* parent;
}BiTNode;										//��������� 
typedef BiTNode* BiTree;						//ָ�����������ָ��

void fx(BiTree T)						//�ؼ��Ƿֱ浱ǰ���ڼ��α����� 
{
	BiTree p = T;
	
	while(p)
	{	
 		if(p->lchild)							//��һ�η��ʽ�㣬������� 
 			p = p->lchild;
		else
		{	
			while(!(p->rchild))					
			{									//����ǰ��������ҷ�֧�����ص�������Ҫ���������
				while(p->parent && p->parent->rchild==p)
					p = p->parent;				//�����������صĽ������α����ʣ������ 
					
				if(p->parent)
				{
					if(p->parent->lchild==p)	//����ǰ����������֧�����ص�������Ҫ���ʸ����	 
					{
						p = p->parent;
					
					}
				}
				else
					return;						//�����������ص������ʱ��������� 
			}
			
			p = p->rchild;
		}
	}
}
