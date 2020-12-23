typedef int TElemType;						
typedef struct BiTNode							//二叉树二叉链表存储表示
{
	int data;								//结点元素 
	struct BiTNode* lchild;						//左孩子指针 
	struct BiTNode* rchild;						//右孩子指针
	struct BiTNode* parent;
}BiTNode;										//二叉树结点 
typedef BiTNode* BiTree;						//指向二叉树结点的指针

void fx(BiTree T)						//关键是分辨当前结点第几次被访问 
{
	BiTree p = T;
	
	while(p)
	{	
 		if(p->lchild)							//第一次访问结点，向左访问 
 			p = p->lchild;
		else
		{	
			while(!(p->rchild))					
			{									//若当前结点属于右分支，返回到父结点后要跳过父结点
				while(p->parent && p->parent->rchild==p)
					p = p->parent;				//从右子树返回的结点第三次被访问，不输出 
					
				if(p->parent)
				{
					if(p->parent->lchild==p)	//若当前结点属于左分支，返回到父结点后要访问父结点	 
					{
						p = p->parent;
					
					}
				}
				else
					return;						//从右子树返回到根结点时，遍历完成 
			}
			
			p = p->rchild;
		}
	}
}
