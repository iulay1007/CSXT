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
 
void BubbleSortPlus(SqList *L)
{
	int i, j;
	RedType tmp;
	int change;							//change指示每一趟排序中进行交换的最后一个记录的位置
	
	for(i=(*L).length; i>=1; i=change-1)
	{		
		for(j=1; j<=i-1; j++)
		{
			if(((*L).r[j+1].key<(*L).r[j].key))
			{
				tmp = (*L).r[j+1];
				(*L).r[j+1] = (*L).r[j];
				(*L).r[j] = tmp;
				
				change = j+1;			//从change起往后的元素均有序			 
			} 
		}
		
		if(change==j+1)					//若遍历不发生交换，说明序列已经有序
			break;
	}
}
