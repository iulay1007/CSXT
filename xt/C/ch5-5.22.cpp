#include <iostream>
#define MAXSIZE 100 
#define   eleType int
const int maxsize = 100;
typedef struct
 {
   int row,col; /* ���±�,���±� */
   int ele; /* ����Ԫ��ֵ */
 }Triple;
 typedef struct
 {
   Triple data[MAXSIZE+1]; /* ����Ԫ��Ԫ���,data[0]δ�� */
   int row,col,len; /* ����������������ͷ���Ԫ���� */
 }TSMatrix;
class triple
{
public:
	int row, col;
	eleType ele;
	triple(int row,int col,eleType ele):row(row),col(col),ele(ele){}
	triple():row(0), col(0), ele(0) {}
};
	bool operator==(const triple& a,const triple& b) { return (a.row == b.row && a.col == b.col); }	//�������ж�����Ƿ���ȣ����ж�Ԫ��ֵ

bool TSMadd(TSMatrix& A, TSMatrix B)
{
	if (A.col != B.col || A.row != B.row)	//�����ʽ������˳�
	{
		return 0;
	}
	int m(B.len), n(0), k(-1);
	for (int i = A.len-1; i >=0; i--)	//��A�е�Ԫ��������B.len��λ��
	{
		A.data[i + B.len] = A.data[i];
	}
	
	while (m < A.len + B.len && n < B.len)		//����A��B��Ԫ�صı���
	{
		if (A.data[m].row < B.data[n].row)		//����row�Ƚ�
			A.data[++k] = A.data[m++];
		else if (A.data[m].row > B.data[n].row)
			A.data[++k] = B.data[n++];
		else									//��row������ٱȽ�col
		{
			if (A.data[m].col < B.data[n].col)
				A.data[++k] = A.data[m++];
			else if (A.data[m].col > B.data[n].col)
				A.data[++k] = B.data[n++];
			else
			{
				if (A.data[m].ele + B.data[n].ele)		//����Ҫע����Ǽ�������Ԫ�����Ϊ0����ζ�����ֵ���ܴ���������Ϊ��Ԫ����ֻ�������ֵ
				{
					k++;
					A.data[k].col = A.data[m].col;
					A.data[k].row = A.data[m].row;
					A.data[k].ele = A.data[m].ele + B.data[n].ele;
				}
				m++;	
				n++;
			}
		}
	}
	while (m < A.len + B.len)
		A.data[++k] = A.data[m++];
	while (n < B.len)
		A.data[++k] = B.data[n++];
	A.len = k;
	return 1;
}

