#include <stdio.h>
#include <malloc.h> 
typedef struct LNode{
	int data;
	LNode *next;
	
}LNode,*LinkList;

int DeleteAndInsertSub(LinkList la,LinkList lb,int i,int len){
	if(i<0||len<0)
	return -1;
	LinkList front_a;
	LinkList front_b;
	LinkList tail_b;
	LinkList tail_a;
	int t=1;
	while(t<=i)
	{
		front_a=la;
		front_b=lb;
		la=la->next;
		lb=lb->next;
		t++;
	}
	tail_a=la;
	for(int k=1;k<len;k++)
	tail_a=tail_a->next;
	front_a->next=tail_a->next;
	front_b->next=la;
	tail_a->next=lb;
	 
	return 1;
	
	
}
int InitList(LinkList *L)
 { /* �������������һ���յ����Ա�L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     return -1;
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return 1;
 }
int ListInsert(LinkList L,int i,int e) /* �㷨2.9�����ı�L */
 { /* �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) /* iС��1���ߴ��ڱ� */
     return -1;
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ����L�� */
   s->next=p->next;
   p->next=s;
   return 1;
 }
 int ListTraverse(LinkList L)
 /* vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ */
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   LinkList p=L->next;
   while(p)
   {
   	printf("%d ",p->data);
     p=p->next;
   }
   printf("\n");
   return 1;
 }
 
 int main(){
 	LinkList LA,LB; 
 	InitList(&LA);
 	InitList(&LB);
 	for(int j=1;j<=5;j++)
    ListInsert(LA,1,j);
    for(int j=1;j<=5;j++)
    ListInsert(LB,1,j*2);
    DeleteAndInsertSub(LA,LB,2,2);
    ListTraverse(LA);
    ListTraverse(LB);
    return 0; 
 }
