#include <stdio.h>
#include <malloc.h>
#define  ElemType int
typedef struct OLNode
 {
   int i,j; /* 该非零元的行和列下标 */
   ElemType e; /* 非零元素值 */
   struct OLNode *right,*down; /* 该非零元所在行表和列表的后继链域 */
 }OLNode,*OLink;
 typedef struct
 {
   OLink *rhead,*chead; /* 行和列链表头指针向量基址,由CreatSMatrix_OL()分配 */
   int mu,nu,tu; /* 稀疏矩阵的行数、列数和非零元个数 */
 }CrossList;
 
 int InitSMatrix(CrossList *M) /* 加 */
 { /* 初始化M(CrossList类型的变量必须初始化,否则创建、复制矩阵将出错) */
   (*M).rhead=(*M).chead=NULL;
   (*M).mu=(*M).nu=(*M).tu=0;
   return 1;
 }
 
int CreateSMatrix(CrossList *M)
 { /* 创建稀疏矩阵M,采用十字链表存储表示。算法5.4 */
   int i,j,k,m,n,t;
   ElemType e;
   OLNode *p,*q;
   printf("请输入稀疏矩阵的行数 列数 非零元个数: ");
   scanf("%d%d%d",&m,&n,&t);
   (*M).mu=m;
   (*M).nu=n;
   (*M).tu=t;
   (*M).rhead=(OLink*)malloc((m+1)*sizeof(OLink));
   (*M).chead=(OLink*)malloc((n+1)*sizeof(OLink));
  
   for(k=1;k<=m;k++) /* 初始化行头指针向量;各行链表为空链表 */
     (*M).rhead[k]=NULL;
   for(k=1;k<=n;k++) /* 初始化列头指针向量;各列链表为空链表 */
     (*M).chead[k]=NULL;
   printf("请按任意次序输入%d个非零元的行 列 元素值:\n",(*M).tu);
   for(k=0;k<t;k++)
   {
     scanf("%d%d%d",&i,&j,&e);
     p=(OLNode*)malloc(sizeof(OLNode));
     p->i=i; /* 生成结点 */
     p->j=j;
     p->e=e;
     if((*M).rhead[i]==NULL||(*M).rhead[i]->j>j) /* p插在该行的第一个结点处 */
     {
       p->right=(*M).rhead[i];
       (*M).rhead[i]=p;
     }
     else /* 寻查在行表中的插入位置 */
     {
       for(q=(*M).rhead[i];q->right&&q->right->j<j;q=q->right);
       p->right=q->right; /* 完成行插入 */
       q->right=p;
     }
     if((*M).chead[j]==NULL||(*M).chead[j]->i>i) /* p插在该列的第一个结点处 */
     {
       p->down=(*M).chead[j];
       (*M).chead[j]=p;
     }
     else /* 寻查在列表中的插入位置 */
     {
       for(q=(*M).chead[j];q->down&&q->down->i<i;q=q->down);
       p->down=q->down; /* 完成列插入 */
       q->down=p;
     }
   }
   return 1;
 }

int PrintSMatrix(CrossList M)
 { /* 初始条件: 稀疏矩阵M存在。操作结果: 按行或按列输出稀疏矩阵M */
   int i,j;
   OLink p;
   printf("%d行%d列%d个非零元素\n",M.mu,M.nu,M.tu);
   printf("请输入选择(1.按行输出 2.按列输出): ");
   scanf("%d",&i);
   switch(i)
   {
     case 1: for(j=1;j<=M.mu;j++)
             {
               p=M.rhead[j];
               while(p)
               {
                 printf("%d行%d列值为%d\n",p->i,p->j,p->e);
                 p=p->right;
               }
             }
             break;
     case 2: for(j=1;j<=M.nu;j++)
             {
               p=M.chead[j];
               while(p)
               {
                 printf("%d行%d列值为%d\n",p->i,p->j,p->e);
                 p=p->down;
               }
             }
   }
   return 1;
 }
 
 int printfCrossList (CrossList M)
{
	int i, j;
	OLNode *p;
	
	if(!M.tu)
		return 0;
	
	for(i=1; i<=M.mu; ++i)
	{
		p = M.rhead[i];
		for(j=1; j<=M.nu; ++j)
		{
			if(p && p->j==j)
			{
				printf("(%2d %2d %3d)\n", i, j, p->e);
				p = p->right;
			}
		}
	}
	
	return 1;
}
