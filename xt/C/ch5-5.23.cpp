#include <stdio.h>
#define MAXSIZE 100 
typedef struct
 {
   int row,col; /* ���±�,���±� */
   int ele; /* ����Ԫ��ֵ */
 }Triple;
 typedef struct
 {
   Triple *q;//ָ�����Ԫ��ָ�� 
   int p[MAXSIZE];
   int row,col,len; /* ����������������ͷ���Ԫ���� */
 }TSMatrix;
  
  void create(int a , int b , int c){
  	Triple* tr;
  	TSMatrix ts;
  	tr=new Triple[c];
  	for(int i=0;i<c;i++){
  		printf("�����б��ֵ");
		  scanf("%d%d",tr[i].col,tr[i].ele) ;
	  }
	  
	for(int i=0;i<a;i++)
	{
		printf("����ÿһ�е�һ������Ԫ�ڶ�Ԫ�����ţ�û����-1"); 
		scanf("%d",ts.p[i]);
	}
  } 
