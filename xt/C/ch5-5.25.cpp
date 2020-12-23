#define Mu 20								//假设矩阵行数最大值为20 
#define Nu 20								//假设矩阵列数最大值为20
#define MAXSIZE 400							//假设非零元个数的最大值为400

/* 类型定义 */
typedef struct
{
	int mu, nu, tu;							//矩阵行数，列数，非零元个数 
	int V[MAXSIZE+1];						//存储矩阵的元素
	int B[Mu+1][Nu+1];						//标记矩阵中各位置元素是否为非零元 
}Matrix;
int createMatrix(Matrix P, Matrix Q, Matrix *R)		//舍弃0号单元 
{
	int i, j;
	int p, q, r;
	
	if(P.mu!=Q.mu || P.nu!=Q.nu)
	{
		return 0;
	}
	
	(*R).mu = P.mu;
	(*R).nu = P.nu;
	(*R).tu = 0;
	
	p = q = r = 1;
	
	for(i=1; i<=P.mu; ++i)
	{
		for(j=1; j<=P.nu; ++j)
		{
			if(P.B[i][j]==0 && Q.B[i][j]==0)		
				(*R).B[i][j] = 0;
			else if(P.B[i][j]==0 && Q.B[i][j]==1)
			{
				(*R).V[r++] = Q.V[q++];
				(*R).B[i][j] = 1;
				(*R).tu++;
			}
			else if(P.B[i][j]==1 && Q.B[i][j]==0)
			{
				(*R).V[r++] = P.V[p++];
				(*R).B[i][j] = 1;
				(*R).tu++;
			}
			else			
			{
				if(P.V[p]+Q.V[q])
				{
					(*R).V[r++] = P.V[p++] + Q.V[q++];
					(*R).B[i][j] = 1;
					(*R).tu++;
				}
				else
				{
					p++;
					q++;
					(*R).B[i][j] = 0;
				}
			}		
		}
	}
	
	return 1;
}

