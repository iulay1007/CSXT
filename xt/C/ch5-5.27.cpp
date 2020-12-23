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
 
int AddSMatrix(CrossList M,CrossList N,CrossList *Q)
 { /* ��ʼ����: ϡ�����M��N��������������Ӧ��ȡ� */
   /* �������: ��ϡ�����ĺ�Q=M+N */
   int i,k;
   OLink p,pq,pm,pn;
   OLink *col;
   if(M.mu!=N.mu||M.nu!=N.nu)
   {
    return 0;
     
   }
   (*Q).mu=M.mu; /* ��ʼ��Q���� */
   (*Q).nu=M.nu;
   (*Q).tu=0; /* Ԫ�ظ����ĳ�ֵ */
   (*Q).rhead=(OLink*)malloc(((*Q).mu+1)*sizeof(OLink));
   (*Q).chead=(OLink*)malloc(((*Q).nu+1)*sizeof(OLink));
   for(k=1;k<=(*Q).mu;k++) /* ��ʼ��Q����ͷָ������;��������Ϊ������ */
     (*Q).rhead[k]=NULL;
   for(k=1;k<=(*Q).nu;k++) /* ��ʼ��Q����ͷָ������;��������Ϊ������ */
     (*Q).chead[k]=NULL;
   col=(OLink*)malloc(((*Q).nu+1)*sizeof(OLink)); /* ����ָ���е����������� */
  
   for(k=1;k<=(*Q).nu;k++) /* ����ֵ */
     col[k]=NULL;
   for(i=1;i<=M.mu;i++) /* ���е�˳����� */
   {
     pm=M.rhead[i]; /* pmָ�����M�ĵ�i�еĵ�1����� */
     pn=N.rhead[i]; /* pnָ�����N�ĵ�i�еĵ�1����� */
     while(pm&&pn) /* pm��pn������ */
     {
       if(pm->j<pn->j) /* ����M��ǰ������С�ھ���N��ǰ������ */
       {
         p=(OLink)malloc(sizeof(OLNode)); /* ���ɾ���Q�Ľ�� */
        
         (*Q).tu++; /* ����Ԫ������1 */
         p->i=i; /* ����㸳ֵ */
         p->j=pm->j;
         p->e=pm->e;
         p->right=NULL;
         pm=pm->right; /* pmָ�������� */
       }
       else if(pm->j>pn->j) /* ����M��ǰ�����д��ھ���N��ǰ������ */
       {
         p=(OLink)malloc(sizeof(OLNode)); /* ���ɾ���Q�Ľ�� */
         
         (*Q).tu++; /* ����Ԫ������1 */
         p->i=i; /* ����㸳ֵ */
         p->j=pn->j;
         p->e=pn->e;
         p->right=NULL;
         pn=pn->right; /* pnָ�������� */
       }
       else if(pm->e+pn->e) /* ����M��N��ǰ�������������Ԫ��֮�Ͳ�Ϊ0 */
       {
         p=(OLink)malloc(sizeof(OLNode)); /* ���ɾ���Q�Ľ�� */
        
         (*Q).tu++; /* ����Ԫ������1 */
         p->i=i; /* ����㸳ֵ */
         p->j=pn->j;
         p->e=pm->e+pn->e;
         p->right=NULL;
         pm=pm->right; /* pmָ�������� */
         pn=pn->right; /* pnָ�������� */
       }
       else /* ����M��N��ǰ�������������Ԫ��֮��Ϊ0 */
       {
         pm=pm->right; /* pmָ�������� */
         pn=pn->right; /* pnָ�������� */
         continue;
       }
       if((*Q).rhead[i]==NULL) /* pΪ���еĵ�1����� */
         (*Q).rhead[i]=pq=p; /* p���ڸ��еı�ͷ��pqָ��p(���е����һ�����) */
       else /* ����pq��ָ���֮�� */
       {
         pq->right=p; /* ����в��� */
         pq=pq->right; /* pqָ����е����һ����� */
       }
       if((*Q).chead[p->j]==NULL) /* pΪ���еĵ�1����� */
         (*Q).chead[p->j]=col[p->j]=p; /* p���ڸ��еı�ͷ��col[p->j]ָ��p */
       else /* ����col[p->]��ָ���֮�� */
       {
         col[p->j]->down=p; /* ����в��� */
         col[p->j]=col[p->j]->down; /* col[p->j]ָ����е����һ����� */
       }
     }
     while(pm) /* ������M���е�ʣ��Ԫ�ز������Q */
     {
       p=(OLink)malloc(sizeof(OLNode)); /* ���ɾ���Q�Ľ�� */
      
       (*Q).tu++; /* ����Ԫ������1 */
       p->i=i; /* ����㸳ֵ */
       p->j=pm->j;
       p->e=pm->e;
       p->right=NULL;
       pm=pm->right; /* pmָ�������� */
       if((*Q).rhead[i]==NULL) /* pΪ���еĵ�1����� */
         (*Q).rhead[i]=pq=p; /* p���ڸ��еı�ͷ��pqָ��p(���е����һ�����) */
       else /* ����pq��ָ���֮�� */
       {
         pq->right=p; /* ����в��� */
         pq=pq->right; /* pqָ����е����һ����� */
       }
       if((*Q).chead[p->j]==NULL) /* pΪ���еĵ�1����� */
         (*Q).chead[p->j]=col[p->j]=p; /* p���ڸ��еı�ͷ��col[p->j]ָ��p */
       else /* ����col[p->j]��ָ���֮�� */
       {
         col[p->j]->down=p; /* ����в��� */
         col[p->j]=col[p->j]->down; /* col[p->j]ָ����е����һ����� */
       }
     }
     while(pn) /* ������N���е�ʣ��Ԫ�ز������Q */
     {
       p=(OLink)malloc(sizeof(OLNode)); /* ���ɾ���Q�Ľ�� */
      
       (*Q).tu++; /* ����Ԫ������1 */
       p->i=i; /* ����㸳ֵ */
       p->j=pn->j;
       p->e=pn->e;
       p->right=NULL;
       pn=pn->right; /* pmָ�������� */
       if((*Q).rhead[i]==NULL) /* pΪ���еĵ�1����� */
         (*Q).rhead[i]=pq=p; /* p���ڸ��еı�ͷ��pqָ��p(���е����һ�����) */
       else /* ����pq��ָ���֮�� */
       {
         pq->right=p; /* ����в��� */
         pq=pq->right; /* pqָ����е����һ����� */
       }
       if((*Q).chead[p->j]==NULL) /* pΪ���еĵ�1����� */
         (*Q).chead[p->j]=col[p->j]=p; /* p���ڸ��еı�ͷ��col[p->j]ָ��p */
       else /* ����col[p->j]��ָ���֮�� */
       {
         col[p->j]->down=p; /* ����в��� */
         col[p->j]=col[p->j]->down; /* col[p->j]ָ����е����һ����� */
       }
     }
   }
   for(k=1;k<=(*Q).nu;k++)
     if(col[k]) /* k���н�� */
       col[k]->down=NULL; /*  ��������һ������downָ��Ϊ�� */
   free(col);
   return 1;
 }
