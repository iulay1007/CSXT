#define MAXSIZE 20 /* һ������ʾ����С˳������󳤶� */
 typedef int KeyType; /* ����ؼ�������Ϊ���� */
 typedef struct
 {
   KeyType key; /* �ؼ����� */
 //  InfoType otherinfo; /* ������������������������ж��� */
 }RedType; /* ��¼���� */

 typedef struct
 {
   RedType r[MAXSIZE+1]; /* r[0]���û������ڱ���Ԫ */
   int length; /* ˳����� */
 }SqList; /* ˳������� */
 
 //�𰸵�˼·�� 
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
		
		if(!tag)								//������������������˵�������Ѿ�����
			break;		
		
		dir = -dir;								//!!�ı䷽��
		
		cache = start;
		start = end + 2*dir;					//��ǰ����������ϴα����յ�Ĺ�ϵ 
		end = cache + dir; 						//��ǰ�����յ����ϴα������Ĺ�ϵ
	}
}

