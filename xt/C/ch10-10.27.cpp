#include <stdio.h>
//交换数字 
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
 
//双向起泡排序 
void bubbleSort(int a[],int n){
	int low=0,high=n-1;
	int i,j;
	int flag=1;//一趟排序结束是否有交换 
	while(low<high&&flag) {//循环跳出条件 ，当flag为0说明已没有逆序 
		flag=0;	//每趟初始flag为0； 
		for(i=low;i<high;i++){//从前往后起泡 
			if(a[i]>a[i+1]){
				swap(&a[i],&a[i+1]);
				flag=1;	
			}
		}
		high--;//从前往后结束后更新上界 
		for(j=high;j>low;j--){//从后往前起泡 
			if(a[j]<a[j-1]){
				swap(&a[j],&a[j-1]);
				flag=1;
			}
		}
		low++;//从后往前结束后更新下届 
	} 
}
 
int main(){
	int a[10]={4,5,2,3,6,7,1,0,9,8};
	bubbleSort(a,10);
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
