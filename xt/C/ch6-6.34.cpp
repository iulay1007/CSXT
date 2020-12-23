#define MAX 100
int dfs(int T[MAX+1], int v, int u)
{
	if(T[u]==v)
		return 1;
	else
	{
		if(T[u] && dfs(T, v, T[u]))
			return 1;
	}
	
	return 0;
}
