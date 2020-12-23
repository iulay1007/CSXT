#define MAXSIZE 20 /* 一个用作示例的小顺序表的最大长度 */
 typedef int KeyType; /* 定义关键字类型为整型 */
 typedef struct
 {
   KeyType key; /* 关键字项 */
 //  InfoType otherinfo; /* 其它数据项，具体类型在主程中定义 */
 }RedType; /* 记录类型 */

 typedef struct
 {
   RedType r[MAXSIZE+1]; /* r[0]闲置或用作哨兵单元 */
   int length; /* 顺序表长度 */
 }SqList; /* 顺序表类型 */
 
int InsertSort(SqList &L)
 { /* 对顺序表L作直接插入排序。算法10.1 */
   int i,j,k;
   k=L.length;
   for(i=k-1;i>=1;i--)
     if (L.r[i+1].key<L.r[i].key) /* "<",需将L.r[i]插入有序子表 */
     {
       L.r[k+1]=L.r[i]; /* 复制为哨兵 */
       for(j=i-1;(L.r[j+1].key<L.r[k+1].key);j++)
	 L.r[j]=L.r[j+1]; /* 记录后移 */
       L.r[j]=L.r[k+1]; /* 插入到正确位置 */
     }
     return 0;
 }
