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
   if(i<1||i>L.length+1) /* iֵ���Ϸ� */
     return 0;
   if(L.length>=L.listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+1)*sizeof(int));
     if(!newbase)
      return -1; /* �洢����ʧ�� */
     L.elem=newbase; /* �»�ַ */
     L.listsize+=1; /* ���Ӵ洢���� */
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
 { /* �������������һ���յ�˳�����Ա� */
   L.elem=(int*)malloc(10*sizeof(int));
   if(!L.elem)
    return -1; /* �洢����ʧ�� */
   L.length=0; /* �ձ���Ϊ0 */
   L.listsize=10; /* ��ʼ�洢���� */
   return 1;
 }
 
 int ListInsert(SqList &L,int i,int e) 
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 */
   /* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
   int *newbase,*q,*p;
   if(i<1||i>L.length+1) /* iֵ���Ϸ� */
     return 0;
   if(L.length>=L.listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+1)*sizeof(int));
     if(!newbase)
      return -1; /* �洢����ʧ�� */
     L.elem=newbase; /* �»�ַ */
     L.listsize+=1; /* ���Ӵ洢���� */
   }
   q=L.elem+i-1; /* qΪ����λ�� */
   for(p=L.elem+L.length-1;p>=q;--p) /* ����λ�ü�֮���Ԫ������ */
     *(p+1)=*p;
   *q=e; /* ����e */
   ++L.length; /* ����1 */
   return 1;
 }

