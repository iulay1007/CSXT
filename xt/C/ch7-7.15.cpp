 #include <string.h>
#include <limits.h> 
#include <stdio.h>
#include <malloc.h>
 #define MAX_INFO 20
 #define INFINITY INT_MAX /* ���������ֵ����� */
 #define MAX_VERTEX_NUM 20 /* ��󶥵���� */
 #define MAX_NAME 5 /* �����ַ�������󳤶�+1 */
 typedef int VRType;
 typedef char InfoType;
 typedef char VertexType[MAX_NAME];
 typedef enum{DG,DN,AG,AN}GraphKind; /* {����ͼ,������,����ͼ,������} */
 typedef struct
 {
   VRType adj; /* �����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ� */
	       /* �Դ�Ȩͼ��c��ΪȨֵ���� */
   InfoType *info; /* �û������Ϣ��ָ��(����) */
 }ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 typedef struct
 {
   VertexType vexs[MAX_VERTEX_NUM]; /* �������� */
   AdjMatrix arcs; /* �ڽӾ��� */
   int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
   GraphKind kind; /* ͼ�������־ */
 }MGraph;

 int LocateVex(MGraph G,VertexType u)
 { /* ��ʼ����:ͼG����,u��G�ж�������ͬ���� */
   /* �������:��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vexs[i])==0)
       return i;
   return -1;
 }
 
 void InsertVex(MGraph *G,VertexType v)
 { /* ��ʼ����: ͼG����,v��ͼG�ж�������ͬ���� */
   /* �������: ��ͼG�������¶���v(�������붥����صĻ�,����InsertArc()ȥ��) */
   int i;
   strcpy((*G).vexs[(*G).vexnum],v); /* �����¶������� */
   for(i=0;i<=(*G).vexnum;i++)
   {
     if((*G).kind%2) /* �� */
     {
       (*G).arcs[(*G).vexnum][i].adj=INFINITY; /* ��ʼ�������ڽӾ����ֵ(�ޱ߻�) */
       (*G).arcs[i][(*G).vexnum].adj=INFINITY; /* ��ʼ�������ڽӾ����ֵ(�ޱ߻�) */
     }
     else /* ͼ */
     {
       (*G).arcs[(*G).vexnum][i].adj=0; /* ��ʼ�������ڽӾ����ֵ(�ޱ߻�) */
       (*G).arcs[i][(*G).vexnum].adj=0; /* ��ʼ�������ڽӾ����ֵ(�ޱ߻�) */
     }
     (*G).arcs[(*G).vexnum][i].info=NULL; /* ��ʼ�������Ϣָ�� */
     (*G).arcs[i][(*G).vexnum].info=NULL;
   }
   (*G).vexnum+=1; /* ͼG�Ķ�������1 */
 }

 int DeleteVex(MGraph *G,VertexType v)
 { /* ��ʼ����: ͼG����,v��G��ĳ�����㡣�������: ɾ��G�ж���v������صĻ� */
   int i,j,k;
   VRType m=0;
   k=LocateVex(*G,v); /* kΪ��ɾ������v����� */
   if(k<0) /* v����ͼG�Ķ��� */
     return 0;
   if((*G).kind==DN||(*G).kind==AN) /* �� */
     m=INFINITY;
   for(j=0;j<(*G).vexnum;j++)
     if((*G).arcs[j][k].adj!=m) /* ���뻡��� */
     {
       if((*G).arcs[j][k].info) /* �������Ϣ */
         free((*G).arcs[j][k].info); /* �ͷ������Ϣ */
       (*G).arcnum--; /* �޸Ļ��� */
     }
   if((*G).kind==DG||(*G).kind==DN) /* ���� */
     for(j=0;j<(*G).vexnum;j++)
       if((*G).arcs[k][j].adj!=m) /* �г��� */
       {
         if((*G).arcs[k][j].info) /* �������Ϣ */
           free((*G).arcs[k][j].info); /* �ͷ������Ϣ */
         (*G).arcnum--; /* �޸Ļ��� */
       }
   for(j=k+1;j<(*G).vexnum;j++) /* ���k����Ķ�����������ǰ�� */
     strcpy((*G).vexs[j-1],(*G).vexs[j]);
   for(i=0;i<(*G).vexnum;i++)
     for(j=k+1;j<(*G).vexnum;j++)
       (*G).arcs[i][j-1]=(*G).arcs[i][j]; /* �ƶ���ɾ������֮��ľ���Ԫ�� */
   for(i=0;i<(*G).vexnum;i++)
     for(j=k+1;j<(*G).vexnum;j++)
       (*G).arcs[j-1][i]=(*G).arcs[j][i]; /* �ƶ���ɾ������֮�µľ���Ԫ�� */
   (*G).vexnum--; /* ����ͼ�Ķ����� */
   return 1;
 }

 int InsertArc(MGraph *G,VertexType v,VertexType w)
 { /* ��ʼ����: ͼG����,v��W��G���������� */
   /* �������: ��G������<v,w>,��G�������,������Գƻ�<w,v> */
   int i,l,v1,w1;
   char *info,s[MAX_INFO];
   v1=LocateVex(*G,v); /* β */
   w1=LocateVex(*G,w); /* ͷ */
   if(v1<0||w1<0)
     return 0;
   (*G).arcnum++; /* ���������1 */
   if((*G).kind%2) /* �� */
   {
     printf("������˻���ߵ�Ȩֵ: ");
     scanf("%d",&(*G).arcs[v1][w1].adj);
   }
   else /* ͼ */
     (*G).arcs[v1][w1].adj=1;
   printf("�Ƿ��иû���ߵ������Ϣ(0:�� 1:��): ");
   scanf("%d%*c",&i);
   if(i)
   {
     printf("������û���ߵ������Ϣ(<%d���ַ�)��",MAX_INFO);
     gets(s);
     l=strlen(s);
     if(l)
     {
       info=(char*)malloc((l+1)*sizeof(char));
       strcpy(info,s);
       (*G).arcs[v1][w1].info=info;
     }
   }
   if((*G).kind>1) /* ���� */
   {
     (*G).arcs[w1][v1].adj=(*G).arcs[v1][w1].adj;
     (*G).arcs[w1][v1].info=(*G).arcs[v1][w1].info; /* ָ��ͬһ�������Ϣ */
   }
   return 1;
 }

 int DeleteArc(MGraph *G,VertexType v,VertexType w)
 { /* ��ʼ����: ͼG����,v��w��G���������� */
   /* �������: ��G��ɾ����<v,w>,��G�������,��ɾ���Գƻ�<w,v> */
   int v1,w1;
   v1=LocateVex(*G,v); /* β */
   w1=LocateVex(*G,w); /* ͷ */
   if(v1<0||w1<0) /* v1��w1��ֵ���Ϸ� */
     return 0;
   if((*G).kind%2==0) /* ͼ */
     (*G).arcs[v1][w1].adj=0;
   else /* �� */
     (*G).arcs[v1][w1].adj=INFINITY;
   if((*G).arcs[v1][w1].info) /* ��������Ϣ */
   {
     free((*G).arcs[v1][w1].info);
     (*G).arcs[v1][w1].info=NULL;
   }
   if((*G).kind>=2) /* ����,ɾ���Գƻ�<w,v> */
   {
     (*G).arcs[w1][v1].adj=(*G).arcs[v1][w1].adj;
     (*G).arcs[w1][v1].info=NULL;
   }
   (*G).arcnum--;
   return 1;
 }

