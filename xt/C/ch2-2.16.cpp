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
 { /* 操作结果：构造一个空的线性表L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* 产生头结点,并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     return -1;
   (*L)->next=NULL; /* 指针域为空 */
   return 1;
 }
int ListInsert(LinkList L,int i,int e) /* 算法2.9。不改变L */
 { /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) /* 寻找第i-1个结点 */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) /* i小于1或者大于表长 */
     return -1;
   s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
   s->data=e; /* 插入L中 */
   s->next=p->next;
   p->next=s;
   return 1;
 }
 int ListTraverse(LinkList L)
 /* vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 */
 { /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
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
