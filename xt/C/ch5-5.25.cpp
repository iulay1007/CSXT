#define Mu 20								//��������������ֵΪ20 
#define Nu 20								//��������������ֵΪ20
#define MAXSIZE 400							//�������Ԫ���������ֵΪ400

/* ���Ͷ��� */
typedef struct
{
	int mu, nu, tu;							//��������������������Ԫ���� 
	int V[MAXSIZE+1];						//�洢�����Ԫ��
	int B[Mu+1][Nu+1];						//��Ǿ����и�λ��Ԫ���Ƿ�Ϊ����Ԫ 
}Matrix;
int createMatrix(Matrix P, Matrix Q, Matrix *R)		//����0�ŵ�Ԫ 
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

