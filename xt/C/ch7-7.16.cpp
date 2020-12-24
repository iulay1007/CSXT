#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_VERTEX_NUM 20
 #define MAX_NAME 3 /* �����ַ�������󳤶�+1 */
 typedef int InfoType; /* �������Ȩֵ */
 typedef char VertexType[MAX_NAME]; /* �ַ������� */
 typedef enum{DG,DN,AG,AN}GraphKind; /* {����ͼ,������,����ͼ,������} */
 typedef struct ArcNode
 {
   int adjvex; /* �û���ָ��Ķ����λ�� */
   struct ArcNode *nextarc; /* ָ����һ������ָ�� */
   InfoType *info; /* ����Ȩֵָ�룩 */
 }ArcNode; /* ���� */
 typedef struct
 {
   VertexType data; /* ������Ϣ */
   ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
 }VNode,AdjList[MAX_VERTEX_NUM]; /* ͷ��� */
 typedef struct
 {
   AdjList vertices;
   int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
   int kind; /* ͼ�������־ */
 }ALGraph;
 
 
 int LocateVex(ALGraph G,VertexType u)
 { /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
   /* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vertices[i].data)==0)
       return i;
   return -1;
 }


 void InsertVex(ALGraph *G,VertexType v)
 { /* ��ʼ����: ͼG����,v��ͼ�ж�������ͬ���� */
   /* �������: ��ͼG�������¶���v(�������붥����صĻ�,����InsertArc()ȥ��) */
   strcpy((*G).vertices[(*G).vexnum].data,v); /* �����¶������� */
   (*G).vertices[(*G).vexnum].firstarc=NULL;
   (*G).vexnum++; /* ͼG�Ķ�������1 */
 }

 int DeleteVex(ALGraph *G,VertexType v)
 { /* ��ʼ����: ͼG����,v��G��ĳ������ */
   /* �������: ɾ��G�ж���v������صĻ� */
   int i,j;
   ArcNode *p,*q;
   j=LocateVex(*G,v); /* j�Ƕ���v����� */
   if(j<0) /* v����ͼG�Ķ��� */
     return 0;
   p=(*G).vertices[j].firstarc; /* ɾ����vΪ���ȵĻ���� */
   while(p)
   {
     q=p;
     p=p->nextarc;
     if((*G).kind%2) /* �� */
       free(q->info);
     free(q);
     (*G).arcnum--; /* ���������1 */
   }
   (*G).vexnum--; /* ��������1 */
   for(i=j;i<(*G).vexnum;i++) /* ����v����Ķ���ǰ�� */
     (*G).vertices[i]=(*G).vertices[i+1];
   for(i=0;i<(*G).vexnum;i++) /* ɾ����vΪ��ȵĻ�����ұ�Ҫʱ�޸ı���Ķ���λ��ֵ */
   {
     p=(*G).vertices[i].firstarc; /* ָ���1������� */
     while(p) /* �л� */
     {
       if(p->adjvex==j)
       {
         if(p==(*G).vertices[i].firstarc) /* ��ɾ����ǵ�1����� */
         {
           (*G).vertices[i].firstarc=p->nextarc;
           if((*G).kind%2) /* �� */
             free(p->info);
           free(p);
           p=(*G).vertices[i].firstarc;
           if((*G).kind<2) /* ���� */
             (*G).arcnum--; /* ���������1 */
         }
         else
         {
           q->nextarc=p->nextarc;
           if((*G).kind%2) /* �� */
             free(p->info);
           free(p);
           p=q->nextarc;
           if((*G).kind<2) /* ���� */
             (*G).arcnum--; /* ���������1 */
         }
       }
       else
       {
         if(p->adjvex>j)
           p->adjvex--; /* �޸ı���Ķ���λ��ֵ(���) */
         q=p;
         p=p->nextarc;
       }
     }
   }
   return 1;
 }

 int InsertArc(ALGraph *G,VertexType v,VertexType w)
 { /* ��ʼ����: ͼG����,v��w��G���������� */
   /* �������: ��G������<v,w>,��G�������,������Գƻ�<w,v> */
   ArcNode *p;
   int w1,i,j;
   i=LocateVex(*G,v); /* ��β��ߵ���� */
   j=LocateVex(*G,w); /* ��ͷ��ߵ���� */
   if(i<0||j<0)
     return 0;
   (*G).arcnum++; /* ͼG�Ļ���ߵ���Ŀ��1 */
   if((*G).kind%2) /* �� */
   {
     printf("�����뻡(��)%s��%s��Ȩֵ: ",v,w);
     scanf("%d",&w1);
   }
   p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=j;
   if((*G).kind%2) /* �� */
   {
     p->info=(int*)malloc(sizeof(int));
     *(p->info)=w1;
   }
   else
     p->info=NULL;
   p->nextarc=(*G).vertices[i].firstarc; /* ���ڱ�ͷ */
   (*G).vertices[i].firstarc=p;
   if((*G).kind>=2) /* ����,������һ������ */
   {
     p=(ArcNode*)malloc(sizeof(ArcNode));
     p->adjvex=i;
     if((*G).kind==3) /* ������ */
     {
       p->info=(int*)malloc(sizeof(int));
       *(p->info)=w1;
     }
     else
       p->info=NULL;
     p->nextarc=(*G).vertices[j].firstarc; /* ���ڱ�ͷ */
     (*G).vertices[j].firstarc=p;
   }
   return 1;
 }

 int DeleteArc(ALGraph *G,VertexType v,VertexType w)
 { /* ��ʼ����: ͼG����,v��w��G���������� */
   /* �������: ��G��ɾ����<v,w>,��G�������,��ɾ���Գƻ�<w,v> */
   ArcNode *p,*q;
   int i,j;
   i=LocateVex(*G,v); /* i�Ƕ���v(��β)����� */
   j=LocateVex(*G,w); /* j�Ƕ���w(��ͷ)����� */
   if(i<0||j<0||i==j)
     return 0;
   p=(*G).vertices[i].firstarc; /* pָ�򶥵�v�ĵ�һ������ */
   while(p&&p->adjvex!=j) /* p��������ָ֮�����Ǵ�ɾ����<v,w> */
   { /* pָ����һ���� */
     q=p;
     p=p->nextarc;
   }
   if(p&&p->adjvex==j) /* �ҵ���<v,w> */
   {
     if(p==(*G).vertices[i].firstarc) /* p��ָ�ǵ�1���� */
       (*G).vertices[i].firstarc=p->nextarc; /* ָ����һ���� */
     else
       q->nextarc=p->nextarc; /* ָ����һ���� */
     if((*G).kind%2) /* �� */
       free(p->info);
     free(p); /* �ͷŴ˽�� */
     (*G).arcnum--; /* ���������1 */
   }
   if((*G).kind>=2) /* ����,ɾ���Գƻ�<w,v> */
   {
     p=(*G).vertices[j].firstarc; /* pָ϶���w�ĵ�һ������ */
     while(p&&p->adjvex!=i) /* p��������ָ֮�����Ǵ�ɾ����<w,v> */
     { /* pָ����һ���� */
       q=p;
       p=p->nextarc;
     }
     if(p&&p->adjvex==i) /* �ҵ���<w,v> */
     {
       if(p==(*G).vertices[j].firstarc) /* p��ָ�ǵ�1���� */
         (*G).vertices[j].firstarc=p->nextarc; /* ָ����һ���� */
       else
         q->nextarc=p->nextarc; /* ָ����һ���� */
       if((*G).kind==3) /* ������ */
         free(p->info);
       free(p); /* �ͷŴ˽�� */
     }
   }
   return 1;
 }

