#include <stdio.h>
//�������� 
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
 
//˫���������� 
void bubbleSort(int a[],int n){
	int low=0,high=n-1;
	int i,j;
	int flag=1;//һ����������Ƿ��н��� 
	while(low<high&&flag) {//ѭ���������� ����flagΪ0˵����û������ 
		flag=0;	//ÿ�˳�ʼflagΪ0�� 
		for(i=low;i<high;i++){//��ǰ�������� 
			if(a[i]>a[i+1]){
				swap(&a[i],&a[i+1]);
				flag=1;	
			}
		}
		high--;//��ǰ�������������Ͻ� 
		for(j=high;j>low;j--){//�Ӻ���ǰ���� 
			if(a[j]<a[j-1]){
				swap(&a[j],&a[j-1]);
				flag=1;
			}
		}
		low++;//�Ӻ���ǰ����������½� 
	} 
}
 
int main(){
	int a[10]={4,5,2,3,6,7,1,0,9,8};
	bubbleSort(a,10);
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
