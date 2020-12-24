#include<iostream>
using namespace std;
#include<malloc.h>
 
#define MAX_VERTEX_NUM 20
#define VerTexType char
 
typedef enum{DG,DN,UDG,UDN}GraphKind;
 
typedef struct ArcNode//�߽��
{
    int adjvex;//�ڽᶥ��Ķ������
    double weight;
    struct ArcNode *next;
}ArcNode;
 
typedef struct VNode
{
    VerTexType data;
    ArcNode *firststar;
}VNode,AdjList[MAX_VERTEX_NUM];
 
typedef struct ALGraph
{
    AdjList vertices;
    int pointnum;
    int edgenum;
    int kind;
}ALGraph;
 
bool IsExistArc(ALGraph &G,int i,int j)
{
    ArcNode *t;
    for(t =G.vertices[i].firststar;t;t = t->next)
    {
        if(t->adjvex == j)
            return true;
    }
    return false;
}
 
int LocateVexAL(ALGraph &G,VerTexType v)
{
    int i;
    for(i = 0;i<G.pointnum;i++)
    {
        if(v == G.vertices[i].data)
            return i;
    }
    return -1;   
}
 
void CreateADJ(ALGraph &G)
{
    int i;
    int j;
    int k;
    VerTexType temp;
    VerTexType a;
    VerTexType b;
    ArcNode *s;
    G.kind = DG;
    for(k = 0;k < G.pointnum;k++)
    {
        cout<<"�����붥���ֵ"<<endl;
        cin>>temp;
        for(i = 0 ;i<k;i++)
        {
            if(temp== G.vertices[i].data)
                break;
        }
        if(i < k)
        {
            k--;
            cout<<"�Ѿ����������ĵ㣬��������"<<endl;
            continue;
        }
        G.vertices[k].data = temp;
        G.vertices[k].firststar = NULL;
    }
    for(k = 0; k<G.edgenum;k++)
    {
        cout<<"������һ����β";
        cin>>a;
        cout<<"������һ����ͷ";
        cin>>b;
        i = LocateVexAL(G,a);
        j = LocateVexAL(G,b);
        if(i == j || IsExistArc(G,i,j) == true)
        {
            k--;
            cout<<"�Ѿ����������ĵ㣬��������"<<endl;
            continue;
        }
        s = (ArcNode*)malloc(sizeof(ArcNode));
        s ->adjvex = j;
        s->next = G.vertices[i].firststar;
        G.vertices[i].firststar = s;
    }
}
void DispADJ(ALGraph &G)
{
    int k;
    ArcNode *p;
    for(k = 0;k<G.pointnum;k++)
    {
        cout<<"��"<<G.vertices[k].data<<"�������ܵ���Ķ�����";
        for(p = G.vertices[k].firststar;p;p = p->next)
        {
            cout<<G.vertices[p->adjvex].data;
        }
        cout<<endl;
    }
}
 
int main()
{
    ALGraph G;
    cout<<"���붥����"<<endl;
    cin>>G.pointnum;
    cout<<"�������"<<endl;
    cin>>G.edgenum;
    CreateADJ(G);
    DispADJ(G);
}
