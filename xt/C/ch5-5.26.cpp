#include <stdio.h>
#include <malloc.h>
#define  ElemType int
typedef struct OLNode
 {
   int i,j; /* �÷���Ԫ���к����±� */
   ElemType e; /* ����Ԫ��ֵ */
   struct OLNode *right,*down; /* �÷���Ԫ�����б���б�ĺ������ */
 }OLNode,*OLink;
 typedef struct
 {
   OLink *rhead,*chead; /* �к�������ͷָ��������ַ,��CreatSMatrix_OL()���� */
   int mu,nu,tu; /* ϡ�����������������ͷ���Ԫ���� */
 }CrossList;
 
 int InitSMatrix(CrossList *M) /* �� */
 { /* ��ʼ��M(CrossList���͵ı��������ʼ��,���򴴽������ƾ��󽫳���) */
   (*M).rhead=(*M).chead=NULL;
   (*M).mu=(*M).nu=(*M).tu=0;
   return 1;
 }
 
int CreateSMatrix(CrossList *M)
 { /* ����ϡ�����M,����ʮ������洢��ʾ���㷨5.4 */
   int i,j,k,m,n,t;
   ElemType e;
   OLNode *p,*q;
   printf("������ϡ���������� ���� ����Ԫ����: ");
   scanf("%d%d%d",&m,&n,&t);
   (*M).mu=m;
   (*M).nu=n;
   (*M).tu=t;
   (*M).rhead=(OLink*)malloc((m+1)*sizeof(OLink));
   (*M).chead=(OLink*)malloc((n+1)*sizeof(OLink));
  
   for(k=1;k<=m;k++) /* ��ʼ����ͷָ������;��������Ϊ������ */
     (*M).rhead[k]=NULL;
   for(k=1;k<=n;k++) /* ��ʼ����ͷָ������;��������Ϊ������ */
     (*M).chead[k]=NULL;
   printf("�밴�����������%d������Ԫ���� �� Ԫ��ֵ:\n",(*M).tu);
   for(k=0;k<t;k++)
   {
     scanf("%d%d%d",&i,&j,&e);
     p=(OLNode*)malloc(sizeof(OLNode));
     p->i=i; /* ���ɽ�� */
     p->j=j;
     p->e=e;
     if((*M).rhead[i]==NULL||(*M).rhead[i]->j>j) /* p���ڸ��еĵ�һ����㴦 */
     {
       p->right=(*M).rhead[i];
       (*M).rhead[i]=p;
     }
     else /* Ѱ�����б��еĲ���λ�� */
     {
       for(q=(*M).rhead[i];q->right&&q->right->j<j;q=q->right);
       p->right=q->right; /* ����в��� */
       q->right=p;
     }
     if((*M).chead[j]==NULL||(*M).chead[j]->i>i) /* p���ڸ��еĵ�һ����㴦 */
     {
       p->down=(*M).chead[j];
       (*M).chead[j]=p;
     }
     else /* Ѱ�����б��еĲ���λ�� */
     {
       for(q=(*M).chead[j];q->down&&q->down->i<i;q=q->down);
       p->down=q->down; /* ����в��� */
       q->down=p;
     }
   }
   return 1;
 }

int PrintSMatrix(CrossList M)
 { /* ��ʼ����: ϡ�����M���ڡ��������: ���л������ϡ�����M */
   int i,j;
   OLink p;
   printf("%d��%d��%d������Ԫ��\n",M.mu,M.nu,M.tu);
   printf("������ѡ��(1.������� 2.�������): ");
   scanf("%d",&i);
   switch(i)
   {
     case 1: for(j=1;j<=M.mu;j++)
             {
               p=M.rhead[j];
               while(p)
               {
                 printf("%d��%d��ֵΪ%d\n",p->i,p->j,p->e);
                 p=p->right;
               }
             }
             break;
     case 2: for(j=1;j<=M.nu;j++)
             {
               p=M.chead[j];
               while(p)
               {
                 printf("%d��%d��ֵΪ%d\n",p->i,p->j,p->e);
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
