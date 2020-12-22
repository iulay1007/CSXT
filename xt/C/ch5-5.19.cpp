#include <stdio.h>
#include <limits.h>
#define m 4
#define n 4
int findPoint(int num[m][n]){
	
	int l[m];
	int h[n];
	
	for(int i=0;i<m;i++)
	{
		int max=INT_MIN;;
		for(int j=0;j<n;j++)
		{
			max=num[i][j]>max?num[i][j]:max;
			
		 } 
		 l[i]=max;
	}
	
	for(int i=0;i<n;i++)
	{
		int max=INT_MIN;;
		for(int j=0;j<m;j++)
		{
		max=num[j][i]>max?num[j][i]:max;		
		} 
		h[i]=max;
	}
	
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		if(num[i][j]==l[i]&&num[i][j]==h[j])
		printf("%d %d -",i,j);
	} 
	
	return 1;
}

int main(){
	int num[m][n]={{1,2,3,4},{3,1,4,5},{3,0,2,1}};
	findPoint(num);
	
	return 0;
}
