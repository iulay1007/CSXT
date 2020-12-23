#include <stdio.h> 
#define MAX 100
int dfs(int L[MAX+1], int R[MAX+1], int v, int u)
{
	if(L[v]==u || R[v]==u)
		return 1;
	else
	{
		if(L[v]!=NULL && dfs(L, R, L[v], u))
			return 1;
		if(R[v]!=NULL && dfs(L, R, R[v], u))
			return 1;
	}
	
	return 0;
}
