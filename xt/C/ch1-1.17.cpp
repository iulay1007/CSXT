#include <stdio.h>

//聪明的我写的
//答案sb！！！！ 
int Fb(int k,int n){
		int result=0;
	if(n<k-1)
	return 0;
	else if(n==k-1)
	return 1;
	for(int i=1;i<=k;i++)
	{
		 result=result+Fb(k,n-i);
	 } 
	 return result;
}

int main(){
	
	printf("%d\n",Fb(1,9));
	return 0;
}
