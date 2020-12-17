#include <stdio.h>
#include <malloc.h>
typedef struct{
	int *elem;
	int length;
	int listsize; 
}SqList;

int ListInsert(SqList &L,int i,int e);
int InitList(SqList &L) ;
  
  int InsertElem(SqList &L,int e){
  	
  	  int *newbase,*q,*p;
  	  int i=1;
   if(i<1||i>L.length+1) /* i值不合法 */
     return 0;
   if(L.length>=L.listsize) /* 当前存储空间已满,增加分配 */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+1)*sizeof(int));
     if(!newbase)
      return -1; /* 存储分配失败 */
     L.elem=newbase; /* 新基址 */
     L.listsize+=1; /* 增加存储容量 */
   }
   while(L.elem[i-1]<e)
   i++;
 //  printf("%d\n",i); 
   for(int j=6;j>=i;j--)
   L.elem[j]=L.elem[j-1];
   
   L.elem[i-1]=e;
    
 	
 	return 0;
   
  }
  
  int main(){
  	 SqList L;
 	 InitList(L);
 	 for(int j=5;j>=1;j--)
     ListInsert(L,1,j*2);
     InsertElem(L,3); 
     for(int j=1;j<=6;j++)
     printf("%d ",*(L.elem+j-1)); 
 	
     return 0;
  	
  } 
  
  
   int InitList(SqList &L) 
 { /* 操作结果：构造一个空的顺序线性表 */
   L.elem=(int*)malloc(10*sizeof(int));
   if(!L.elem)
    return -1; /* 存储分配失败 */
   L.length=0; /* 空表长度为0 */
   L.listsize=10; /* 初始存储容量 */
   return 1;
 }
 
 int ListInsert(SqList &L,int i,int e) 
 { /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1 */
   /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
   int *newbase,*q,*p;
   if(i<1||i>L.length+1) /* i值不合法 */
     return 0;
   if(L.length>=L.listsize) /* 当前存储空间已满,增加分配 */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+1)*sizeof(int));
     if(!newbase)
      return -1; /* 存储分配失败 */
     L.elem=newbase; /* 新基址 */
     L.listsize+=1; /* 增加存储容量 */
   }
   q=L.elem+i-1; /* q为插入位置 */
   for(p=L.elem+L.length-1;p>=q;--p) /* 插入位置及之后的元素右移 */
     *(p+1)=*p;
   *q=e; /* 插入e */
   ++L.length; /* 表长增1 */
   return 1;
 }

