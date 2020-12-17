 #include <stdio.h>
#include <malloc.h>
typedef struct{
	int *elem;
	int length;
	int listsize; 
}SqList;

void  reverseList(SqList head) {
	int p=0;
	int q=head.length-1;
	while(p<q)
	{
		int temp=head.elem[p];
		head.elem[p]=head.elem[q];
		head.elem[q]=temp;
		p++;
		q--;
	 } 
	

} 
