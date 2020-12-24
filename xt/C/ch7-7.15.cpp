 #include <string.h>
#include <limits.h> 
#include <stdio.h>
#include <malloc.h>
 #define MAX_INFO 20
 #define INFINITY INT_MAX /* 用整型最大值代替∞ */
 #define MAX_VERTEX_NUM 20 /* 最大顶点个数 */
 #define MAX_NAME 5 /* 顶点字符串的最大长度+1 */
 typedef int VRType;
 typedef char InfoType;
 typedef char VertexType[MAX_NAME];
 typedef enum{DG,DN,AG,AN}GraphKind; /* {有向图,有向网,无向图,无向网} */
 typedef struct
 {
   VRType adj; /* 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否； */
	       /* 对带权图，c则为权值类型 */
   InfoType *info; /* 该弧相关信息的指针(可无) */
 }ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 typedef struct
 {
   VertexType vexs[MAX_VERTEX_NUM]; /* 顶点向量 */
   AdjMatrix arcs; /* 邻接矩阵 */
   int vexnum,arcnum; /* 图的当前顶点数和弧数 */
   GraphKind kind; /* 图的种类标志 */
 }MGraph;

 int LocateVex(MGraph G,VertexType u)
 { /* 初始条件:图G存在,u和G中顶点有相同特征 */
   /* 操作结果:若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vexs[i])==0)
       return i;
   return -1;
 }
 
 void InsertVex(MGraph *G,VertexType v)
 { /* 初始条件: 图G存在,v和图G中顶点有相同特征 */
   /* 操作结果: 在图G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做) */
   int i;
   strcpy((*G).vexs[(*G).vexnum],v); /* 构造新顶点向量 */
   for(i=0;i<=(*G).vexnum;i++)
   {
     if((*G).kind%2) /* 网 */
     {
       (*G).arcs[(*G).vexnum][i].adj=INFINITY; /* 初始化该行邻接矩阵的值(无边或弧) */
       (*G).arcs[i][(*G).vexnum].adj=INFINITY; /* 初始化该列邻接矩阵的值(无边或弧) */
     }
     else /* 图 */
     {
       (*G).arcs[(*G).vexnum][i].adj=0; /* 初始化该行邻接矩阵的值(无边或弧) */
       (*G).arcs[i][(*G).vexnum].adj=0; /* 初始化该列邻接矩阵的值(无边或弧) */
     }
     (*G).arcs[(*G).vexnum][i].info=NULL; /* 初始化相关信息指针 */
     (*G).arcs[i][(*G).vexnum].info=NULL;
   }
   (*G).vexnum+=1; /* 图G的顶点数加1 */
 }

 int DeleteVex(MGraph *G,VertexType v)
 { /* 初始条件: 图G存在,v是G中某个顶点。操作结果: 删除G中顶点v及其相关的弧 */
   int i,j,k;
   VRType m=0;
   k=LocateVex(*G,v); /* k为待删除顶点v的序号 */
   if(k<0) /* v不是图G的顶点 */
     return 0;
   if((*G).kind==DN||(*G).kind==AN) /* 网 */
     m=INFINITY;
   for(j=0;j<(*G).vexnum;j++)
     if((*G).arcs[j][k].adj!=m) /* 有入弧或边 */
     {
       if((*G).arcs[j][k].info) /* 有相关信息 */
         free((*G).arcs[j][k].info); /* 释放相关信息 */
       (*G).arcnum--; /* 修改弧数 */
     }
   if((*G).kind==DG||(*G).kind==DN) /* 有向 */
     for(j=0;j<(*G).vexnum;j++)
       if((*G).arcs[k][j].adj!=m) /* 有出弧 */
       {
         if((*G).arcs[k][j].info) /* 有相关信息 */
           free((*G).arcs[k][j].info); /* 释放相关信息 */
         (*G).arcnum--; /* 修改弧数 */
       }
   for(j=k+1;j<(*G).vexnum;j++) /* 序号k后面的顶点向量依次前移 */
     strcpy((*G).vexs[j-1],(*G).vexs[j]);
   for(i=0;i<(*G).vexnum;i++)
     for(j=k+1;j<(*G).vexnum;j++)
       (*G).arcs[i][j-1]=(*G).arcs[i][j]; /* 移动待删除顶点之后的矩阵元素 */
   for(i=0;i<(*G).vexnum;i++)
     for(j=k+1;j<(*G).vexnum;j++)
       (*G).arcs[j-1][i]=(*G).arcs[j][i]; /* 移动待删除顶点之下的矩阵元素 */
   (*G).vexnum--; /* 更新图的顶点数 */
   return 1;
 }

 int InsertArc(MGraph *G,VertexType v,VertexType w)
 { /* 初始条件: 图G存在,v和W是G中两个顶点 */
   /* 操作结果: 在G中增添弧<v,w>,若G是无向的,则还增添对称弧<w,v> */
   int i,l,v1,w1;
   char *info,s[MAX_INFO];
   v1=LocateVex(*G,v); /* 尾 */
   w1=LocateVex(*G,w); /* 头 */
   if(v1<0||w1<0)
     return 0;
   (*G).arcnum++; /* 弧或边数加1 */
   if((*G).kind%2) /* 网 */
   {
     printf("请输入此弧或边的权值: ");
     scanf("%d",&(*G).arcs[v1][w1].adj);
   }
   else /* 图 */
     (*G).arcs[v1][w1].adj=1;
   printf("是否有该弧或边的相关信息(0:无 1:有): ");
   scanf("%d%*c",&i);
   if(i)
   {
     printf("请输入该弧或边的相关信息(<%d个字符)：",MAX_INFO);
     gets(s);
     l=strlen(s);
     if(l)
     {
       info=(char*)malloc((l+1)*sizeof(char));
       strcpy(info,s);
       (*G).arcs[v1][w1].info=info;
     }
   }
   if((*G).kind>1) /* 无向 */
   {
     (*G).arcs[w1][v1].adj=(*G).arcs[v1][w1].adj;
     (*G).arcs[w1][v1].info=(*G).arcs[v1][w1].info; /* 指向同一个相关信息 */
   }
   return 1;
 }

 int DeleteArc(MGraph *G,VertexType v,VertexType w)
 { /* 初始条件: 图G存在,v和w是G中两个顶点 */
   /* 操作结果: 在G中删除弧<v,w>,若G是无向的,则还删除对称弧<w,v> */
   int v1,w1;
   v1=LocateVex(*G,v); /* 尾 */
   w1=LocateVex(*G,w); /* 头 */
   if(v1<0||w1<0) /* v1、w1的值不合法 */
     return 0;
   if((*G).kind%2==0) /* 图 */
     (*G).arcs[v1][w1].adj=0;
   else /* 网 */
     (*G).arcs[v1][w1].adj=INFINITY;
   if((*G).arcs[v1][w1].info) /* 有其它信息 */
   {
     free((*G).arcs[v1][w1].info);
     (*G).arcs[v1][w1].info=NULL;
   }
   if((*G).kind>=2) /* 无向,删除对称弧<w,v> */
   {
     (*G).arcs[w1][v1].adj=(*G).arcs[v1][w1].adj;
     (*G).arcs[w1][v1].info=NULL;
   }
   (*G).arcnum--;
   return 1;
 }

