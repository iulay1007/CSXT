#include <stdio.h>
 #define MAXSIZE 100 /* 非零元个数的最大值 */
 typedef struct
 {
   int i,j; /* 行下标,列下标 */
   int e; /* 非零元素值 */
 }Triple;
 typedef struct
 {
   Triple data[MAXSIZE+1]; /* 非零元三元组表,data[0]未用 */
   int mu,nu,tu; /* 矩阵的行数、列数和非零元个数 */
 }TSMatrix;
 int comp(int c1,int c2) /* 另加 */
 { /* AddSMatrix函数要用到 */
   int i;
   if(c1<c2)
     i=1;
   else if(c1==c2)
     i=0;
   else
     i=-1;
   return i;
 }
int add(TSMatrix A,TSMatrix B,TSMatrix &C){
	int m=1;
	int n=1;
	int t=1;
	if(A.mu!=B.mu||A.nu!=B.nu)
	return 0;
	C.mu=A.mu;
	C.nu=A.nu;
	while(m<=A.mu&&n<=B.tu){
		switch(comp(A.data[m].i,B.data[n].i)){
			case -1:
				C.data[t++]=A.data[m++];
				break;
			case 0:
				switch(comp(A.data[m].j,B.data[n].j)){
				case -1:
				C.data[t++]=A.data[m++];
				break;
				case 0:
				C.data[t++]=A.data[m++];
				C.data[t].e+=B.data[n++].e;
				if(C.data[t].e==0)
				t--;}
				break;
			case 1:
			C.data[t++]=B.data[n++];
		}
	}
	while(m<=A.tu)
	C.data[t++]=A.data[m++];
	while(n<=B.tu)
	C.data[t++]=B.data[n++];
	C.tu=t-1; 
	
	return 1; 
}
