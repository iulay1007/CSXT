#include <iostream>
#define MAXSIZE 100 
#define   eleType int
const int maxsize = 100;
typedef struct
 {
   int row,col; /* 行下标,列下标 */
   int ele; /* 非零元素值 */
 }Triple;
 typedef struct
 {
   Triple data[MAXSIZE+1]; /* 非零元三元组表,data[0]未用 */
   int row,col,len; /* 矩阵的行数、列数和非零元个数 */
 }TSMatrix;
class triple
{
public:
	int row, col;
	eleType ele;
	triple(int row,int col,eleType ele):row(row),col(col),ele(ele){}
	triple():row(0), col(0), ele(0) {}
};
	bool operator==(const triple& a,const triple& b) { return (a.row == b.row && a.col == b.col); }	//仅用来判断序号是否相等，不判断元素值

bool TSMadd(TSMatrix& A, TSMatrix B)
{
	if (A.col != B.col || A.row != B.row)	//矩阵格式不相等退出
	{
		return 0;
	}
	int m(B.len), n(0), k(-1);
	for (int i = A.len-1; i >=0; i--)	//把A中的元素往后移B.len个位置
	{
		A.data[i + B.len] = A.data[i];
	}
	
	while (m < A.len + B.len && n < B.len)		//进行A和B的元素的遍历
	{
		if (A.data[m].row < B.data[n].row)		//外层的row比较
			A.data[++k] = A.data[m++];
		else if (A.data[m].row > B.data[n].row)
			A.data[++k] = B.data[n++];
		else									//若row相等则再比较col
		{
			if (A.data[m].col < B.data[n].col)
				A.data[++k] = A.data[m++];
			else if (A.data[m].col > B.data[n].col)
				A.data[++k] = B.data[n++];
			else
			{
				if (A.data[m].ele + B.data[n].ele)		//这里要注意的是假如两者元素相加为0，意味着这个值不能存起来，因为三元组里只储存非零值
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

