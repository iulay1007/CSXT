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
 
int AddSMatrix(CrossList M,CrossList N,CrossList *Q)
 { /* 初始条件: 稀疏矩阵M与N的行数和列数对应相等。 */
   /* 操作结果: 求稀疏矩阵的和Q=M+N */
   int i,k;
   OLink p,pq,pm,pn;
   OLink *col;
   if(M.mu!=N.mu||M.nu!=N.nu)
   {
    return 0;
     
   }
   (*Q).mu=M.mu; /* 初始化Q矩阵 */
   (*Q).nu=M.nu;
   (*Q).tu=0; /* 元素个数的初值 */
   (*Q).rhead=(OLink*)malloc(((*Q).mu+1)*sizeof(OLink));
   (*Q).chead=(OLink*)malloc(((*Q).nu+1)*sizeof(OLink));
   for(k=1;k<=(*Q).mu;k++) /* 初始化Q的行头指针向量;各行链表为空链表 */
     (*Q).rhead[k]=NULL;
   for(k=1;k<=(*Q).nu;k++) /* 初始化Q的列头指针向量;各列链表为空链表 */
     (*Q).chead[k]=NULL;
   col=(OLink*)malloc(((*Q).nu+1)*sizeof(OLink)); /* 生成指向列的最后结点的数组 */
  
   for(k=1;k<=(*Q).nu;k++) /* 赋初值 */
     col[k]=NULL;
   for(i=1;i<=M.mu;i++) /* 按行的顺序相加 */
   {
     pm=M.rhead[i]; /* pm指向矩阵M的第i行的第1个结点 */
     pn=N.rhead[i]; /* pn指向矩阵N的第i行的第1个结点 */
     while(pm&&pn) /* pm和pn均不空 */
     {
       if(pm->j<pn->j) /* 矩阵M当前结点的列小于矩阵N当前结点的列 */
       {
         p=(OLink)malloc(sizeof(OLNode)); /* 生成矩阵Q的结点 */
        
         (*Q).tu++; /* 非零元素数加1 */
         p->i=i; /* 给结点赋值 */
         p->j=pm->j;
         p->e=pm->e;
         p->right=NULL;
         pm=pm->right; /* pm指针向右移 */
       }
       else if(pm->j>pn->j) /* 矩阵M当前结点的列大于矩阵N当前结点的列 */
       {
         p=(OLink)malloc(sizeof(OLNode)); /* 生成矩阵Q的结点 */
         
         (*Q).tu++; /* 非零元素数加1 */
         p->i=i; /* 给结点赋值 */
         p->j=pn->j;
         p->e=pn->e;
         p->right=NULL;
         pn=pn->right; /* pn指针向右移 */
       }
       else if(pm->e+pn->e) /* 矩阵M、N当前结点的列相等且两元素之和不为0 */
       {
         p=(OLink)malloc(sizeof(OLNode)); /* 生成矩阵Q的结点 */
        
         (*Q).tu++; /* 非零元素数加1 */
         p->i=i; /* 给结点赋值 */
         p->j=pn->j;
         p->e=pm->e+pn->e;
         p->right=NULL;
         pm=pm->right; /* pm指针向右移 */
         pn=pn->right; /* pn指针向右移 */
       }
       else /* 矩阵M、N当前结点的列相等且两元素之和为0 */
       {
         pm=pm->right; /* pm指针向右移 */
         pn=pn->right; /* pn指针向右移 */
         continue;
       }
       if((*Q).rhead[i]==NULL) /* p为该行的第1个结点 */
         (*Q).rhead[i]=pq=p; /* p插在该行的表头且pq指向p(该行的最后一个结点) */
       else /* 插在pq所指结点之后 */
       {
         pq->right=p; /* 完成行插入 */
         pq=pq->right; /* pq指向该行的最后一个结点 */
       }
       if((*Q).chead[p->j]==NULL) /* p为该列的第1个结点 */
         (*Q).chead[p->j]=col[p->j]=p; /* p插在该列的表头且col[p->j]指向p */
       else /* 插在col[p->]所指结点之后 */
       {
         col[p->j]->down=p; /* 完成列插入 */
         col[p->j]=col[p->j]->down; /* col[p->j]指向该列的最后一个结点 */
       }
     }
     while(pm) /* 将矩阵M该行的剩余元素插入矩阵Q */
     {
       p=(OLink)malloc(sizeof(OLNode)); /* 生成矩阵Q的结点 */
      
       (*Q).tu++; /* 非零元素数加1 */
       p->i=i; /* 给结点赋值 */
       p->j=pm->j;
       p->e=pm->e;
       p->right=NULL;
       pm=pm->right; /* pm指针向右移 */
       if((*Q).rhead[i]==NULL) /* p为该行的第1个结点 */
         (*Q).rhead[i]=pq=p; /* p插在该行的表头且pq指向p(该行的最后一个结点) */
       else /* 插在pq所指结点之后 */
       {
         pq->right=p; /* 完成行插入 */
         pq=pq->right; /* pq指向该行的最后一个结点 */
       }
       if((*Q).chead[p->j]==NULL) /* p为该列的第1个结点 */
         (*Q).chead[p->j]=col[p->j]=p; /* p插在该列的表头且col[p->j]指向p */
       else /* 插在col[p->j]所指结点之后 */
       {
         col[p->j]->down=p; /* 完成列插入 */
         col[p->j]=col[p->j]->down; /* col[p->j]指向该列的最后一个结点 */
       }
     }
     while(pn) /* 将矩阵N该行的剩余元素插入矩阵Q */
     {
       p=(OLink)malloc(sizeof(OLNode)); /* 生成矩阵Q的结点 */
      
       (*Q).tu++; /* 非零元素数加1 */
       p->i=i; /* 给结点赋值 */
       p->j=pn->j;
       p->e=pn->e;
       p->right=NULL;
       pn=pn->right; /* pm指针向右移 */
       if((*Q).rhead[i]==NULL) /* p为该行的第1个结点 */
         (*Q).rhead[i]=pq=p; /* p插在该行的表头且pq指向p(该行的最后一个结点) */
       else /* 插在pq所指结点之后 */
       {
         pq->right=p; /* 完成行插入 */
         pq=pq->right; /* pq指向该行的最后一个结点 */
       }
       if((*Q).chead[p->j]==NULL) /* p为该列的第1个结点 */
         (*Q).chead[p->j]=col[p->j]=p; /* p插在该列的表头且col[p->j]指向p */
       else /* 插在col[p->j]所指结点之后 */
       {
         col[p->j]->down=p; /* 完成列插入 */
         col[p->j]=col[p->j]->down; /* col[p->j]指向该列的最后一个结点 */
       }
     }
   }
   for(k=1;k<=(*Q).nu;k++)
     if(col[k]) /* k列有结点 */
       col[k]->down=NULL; /*  令该列最后一个结点的down指针为空 */
   free(col);
   return 1;
 }
