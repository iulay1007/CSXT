#include <stdio.h>
#define MAXSIZE 100 
typedef struct
 {
   int row,col; /* 行下标,列下标 */
   int ele; /* 非零元素值 */
 }Triple;
 typedef struct
 {
   Triple *q;//指向非零元的指针 
   int p[MAXSIZE];
   int row,col,len; /* 矩阵的行数、列数和非零元个数 */
 }TSMatrix;
  
  void create(int a , int b , int c){
  	Triple* tr;
  	TSMatrix ts;
  	tr=new Triple[c];
  	for(int i=0;i<c;i++){
  		printf("输入列标和值");
		  scanf("%d%d",tr[i].col,tr[i].ele) ;
	  }
	  
	for(int i=0;i<a;i++)
	{
		printf("输入每一行第一个非零元在二元组的序号，没有输-1"); 
		scanf("%d",ts.p[i]);
	}
  } 
