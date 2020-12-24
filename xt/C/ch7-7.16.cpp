#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_VERTEX_NUM 20
 #define MAX_NAME 3 /* 顶点字符串的最大长度+1 */
 typedef int InfoType; /* 存放网的权值 */
 typedef char VertexType[MAX_NAME]; /* 字符串类型 */
 typedef enum{DG,DN,AG,AN}GraphKind; /* {有向图,有向网,无向图,无向网} */
 typedef struct ArcNode
 {
   int adjvex; /* 该弧所指向的顶点的位置 */
   struct ArcNode *nextarc; /* 指向下一条弧的指针 */
   InfoType *info; /* 网的权值指针） */
 }ArcNode; /* 表结点 */
 typedef struct
 {
   VertexType data; /* 顶点信息 */
   ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
 }VNode,AdjList[MAX_VERTEX_NUM]; /* 头结点 */
 typedef struct
 {
   AdjList vertices;
   int vexnum,arcnum; /* 图的当前顶点数和弧数 */
   int kind; /* 图的种类标志 */
 }ALGraph;
 
 
 int LocateVex(ALGraph G,VertexType u)
 { /* 初始条件: 图G存在,u和G中顶点有相同特征 */
   /* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vertices[i].data)==0)
       return i;
   return -1;
 }


 void InsertVex(ALGraph *G,VertexType v)
 { /* 初始条件: 图G存在,v和图中顶点有相同特征 */
   /* 操作结果: 在图G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做) */
   strcpy((*G).vertices[(*G).vexnum].data,v); /* 构造新顶点向量 */
   (*G).vertices[(*G).vexnum].firstarc=NULL;
   (*G).vexnum++; /* 图G的顶点数加1 */
 }

 int DeleteVex(ALGraph *G,VertexType v)
 { /* 初始条件: 图G存在,v是G中某个顶点 */
   /* 操作结果: 删除G中顶点v及其相关的弧 */
   int i,j;
   ArcNode *p,*q;
   j=LocateVex(*G,v); /* j是顶点v的序号 */
   if(j<0) /* v不是图G的顶点 */
     return 0;
   p=(*G).vertices[j].firstarc; /* 删除以v为出度的弧或边 */
   while(p)
   {
     q=p;
     p=p->nextarc;
     if((*G).kind%2) /* 网 */
       free(q->info);
     free(q);
     (*G).arcnum--; /* 弧或边数减1 */
   }
   (*G).vexnum--; /* 顶点数减1 */
   for(i=j;i<(*G).vexnum;i++) /* 顶点v后面的顶点前移 */
     (*G).vertices[i]=(*G).vertices[i+1];
   for(i=0;i<(*G).vexnum;i++) /* 删除以v为入度的弧或边且必要时修改表结点的顶点位置值 */
   {
     p=(*G).vertices[i].firstarc; /* 指向第1条弧或边 */
     while(p) /* 有弧 */
     {
       if(p->adjvex==j)
       {
         if(p==(*G).vertices[i].firstarc) /* 待删结点是第1个结点 */
         {
           (*G).vertices[i].firstarc=p->nextarc;
           if((*G).kind%2) /* 网 */
             free(p->info);
           free(p);
           p=(*G).vertices[i].firstarc;
           if((*G).kind<2) /* 有向 */
             (*G).arcnum--; /* 弧或边数减1 */
         }
         else
         {
           q->nextarc=p->nextarc;
           if((*G).kind%2) /* 网 */
             free(p->info);
           free(p);
           p=q->nextarc;
           if((*G).kind<2) /* 有向 */
             (*G).arcnum--; /* 弧或边数减1 */
         }
       }
       else
       {
         if(p->adjvex>j)
           p->adjvex--; /* 修改表结点的顶点位置值(序号) */
         q=p;
         p=p->nextarc;
       }
     }
   }
   return 1;
 }

 int InsertArc(ALGraph *G,VertexType v,VertexType w)
 { /* 初始条件: 图G存在,v和w是G中两个顶点 */
   /* 操作结果: 在G中增添弧<v,w>,若G是无向的,则还增添对称弧<w,v> */
   ArcNode *p;
   int w1,i,j;
   i=LocateVex(*G,v); /* 弧尾或边的序号 */
   j=LocateVex(*G,w); /* 弧头或边的序号 */
   if(i<0||j<0)
     return 0;
   (*G).arcnum++; /* 图G的弧或边的数目加1 */
   if((*G).kind%2) /* 网 */
   {
     printf("请输入弧(边)%s→%s的权值: ",v,w);
     scanf("%d",&w1);
   }
   p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=j;
   if((*G).kind%2) /* 网 */
   {
     p->info=(int*)malloc(sizeof(int));
     *(p->info)=w1;
   }
   else
     p->info=NULL;
   p->nextarc=(*G).vertices[i].firstarc; /* 插在表头 */
   (*G).vertices[i].firstarc=p;
   if((*G).kind>=2) /* 无向,生成另一个表结点 */
   {
     p=(ArcNode*)malloc(sizeof(ArcNode));
     p->adjvex=i;
     if((*G).kind==3) /* 无向网 */
     {
       p->info=(int*)malloc(sizeof(int));
       *(p->info)=w1;
     }
     else
       p->info=NULL;
     p->nextarc=(*G).vertices[j].firstarc; /* 插在表头 */
     (*G).vertices[j].firstarc=p;
   }
   return 1;
 }

 int DeleteArc(ALGraph *G,VertexType v,VertexType w)
 { /* 初始条件: 图G存在,v和w是G中两个顶点 */
   /* 操作结果: 在G中删除弧<v,w>,若G是无向的,则还删除对称弧<w,v> */
   ArcNode *p,*q;
   int i,j;
   i=LocateVex(*G,v); /* i是顶点v(弧尾)的序号 */
   j=LocateVex(*G,w); /* j是顶点w(弧头)的序号 */
   if(i<0||j<0||i==j)
     return 0;
   p=(*G).vertices[i].firstarc; /* p指向顶点v的第一条出弧 */
   while(p&&p->adjvex!=j) /* p不空且所指之弧不是待删除弧<v,w> */
   { /* p指向下一条弧 */
     q=p;
     p=p->nextarc;
   }
   if(p&&p->adjvex==j) /* 找到弧<v,w> */
   {
     if(p==(*G).vertices[i].firstarc) /* p所指是第1条弧 */
       (*G).vertices[i].firstarc=p->nextarc; /* 指向下一条弧 */
     else
       q->nextarc=p->nextarc; /* 指向下一条弧 */
     if((*G).kind%2) /* 网 */
       free(p->info);
     free(p); /* 释放此结点 */
     (*G).arcnum--; /* 弧或边数减1 */
   }
   if((*G).kind>=2) /* 无向,删除对称弧<w,v> */
   {
     p=(*G).vertices[j].firstarc; /* p指隙サ鉾的第一条出弧 */
     while(p&&p->adjvex!=i) /* p不空且所指之弧不是待删除弧<w,v> */
     { /* p指向下一条弧 */
       q=p;
       p=p->nextarc;
     }
     if(p&&p->adjvex==i) /* 找到弧<w,v> */
     {
       if(p==(*G).vertices[j].firstarc) /* p所指是第1条弧 */
         (*G).vertices[j].firstarc=p->nextarc; /* 指向下一条弧 */
       else
         q->nextarc=p->nextarc; /* 指向下一条弧 */
       if((*G).kind==3) /* 无向网 */
         free(p->info);
       free(p); /* 释放此结点 */
     }
   }
   return 1;
 }

