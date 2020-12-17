#include <stdio.h>
#include <malloc.h>
typedef struct{
	int *elem;
	int length;
	int listsize; 
}SqList;
 int ListInsert(SqList &L,int i,int e);
  int InitList(SqList &L) ;
int DeleteK(SqList &a,int i,int k)
{
	if(i<1||k<0||i+k>a.length)
	return -1;
	int p=i-1,q=i+k-1;
	for(int j=q;q<a.length;q++)
	{
	a.elem[p]=a.elem[q];
	p++; 
	} 
	a.length-=k;
	return 1;
	
 } 
 
 int main(){
 	 SqList L;
 	 InitList(L);
 	 for(int j=1;j<=5;j++)
     ListInsert(L,1,j);
     DeleteK(L,2,2);
	 for(int j=1;j<=L.length;j++)
     printf("%d ",*(L.elem+j-1)); 
 	
 	
 	return 0;
 }
  int InitList(SqList &L) /* �㷨2.3 */
 { /* �������������һ���յ�˳�����Ա� */
   L.elem=(int*)malloc(10*sizeof(int));
   if(!L.elem)
    return -1; /* �洢����ʧ�� */
   L.length=0; /* �ձ���Ϊ0 */
   L.listsize=10; /* ��ʼ�洢���� */
   return 1;
 }

  int ListInsert(SqList &L,int i,int e) /* �㷨2.4 */
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 */
   /* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
   int *newbase,*q,*p;
   if(i<1||i>L.length+1) /* iֵ���Ϸ� */
     return 0;
   if(L.length>=L.listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+10)*sizeof(int));
     if(!newbase)
      return -1; /* �洢����ʧ�� */
     L.elem=newbase; /* �»�ַ */
     L.listsize+=10; /* ���Ӵ洢���� */
   }
   q=L.elem+i-1; /* qΪ����λ�� */
   for(p=L.elem+L.length-1;p>=q;--p) /* ����λ�ü�֮���Ԫ������ */
     *(p+1)=*p;
   *q=e; /* ����e */
   ++L.length; /* ����1 */
   return 1;
 }
