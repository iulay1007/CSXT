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
 
 //答案的思路！ 
void fx(SqList *L)
{
	int k, start, end, cache, dir;
	RedType tmp;
	int tag;
	
	dir = 1; 
	
	start = 1;
	end = (*L).length;
	
	while(1)
	{
		tag = 0;
							
		for(k=start; k!=end; k=k+dir)
		{
			if(((*L).r[k+1].key< (*L).r[k].key))
			{
				tmp = (*L).r[k+1];
				(*L).r[k+1] = (*L).r[k];
				(*L).r[k] = tmp;
				
				tag = 1;							 
			} 
		}
		
		if(!tag)								//若遍历不发生交换，说明序列已经有序
			break;		
		
		dir = -dir;								//!!改变方向
		
		cache = start;
		start = end + 2*dir;					//当前遍历起点与上次遍历终点的关系 
		end = cache + dir; 						//当前遍历终点与上次遍历起点的关系
	}
}

