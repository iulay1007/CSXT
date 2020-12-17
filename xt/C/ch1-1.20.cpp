#include <stdio.h>
#include<math.h>
int addAll(){
	int x;
	int n;
	int atemp;
	int result=0;
	scanf("%d",&x);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
	scanf("%d",&atemp);
	result+=atemp*(int)pow(x,i);
	}
	printf("%d",result);
	return result;
} 

int main(){
	
	addAll();
	return 0;
}
