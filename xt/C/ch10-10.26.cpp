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
 
void BubbleSortPlus(SqList *L)
{
	int i, j;
	RedType tmp;
	int change;							//changeָʾÿһ�������н��н��������һ����¼��λ��
	
	for(i=(*L).length; i>=1; i=change-1)
	{		
		for(j=1; j<=i-1; j++)
		{
			if(((*L).r[j+1].key<(*L).r[j].key))
			{
				tmp = (*L).r[j+1];
				(*L).r[j+1] = (*L).r[j];
				(*L).r[j] = tmp;
				
				change = j+1;			//��change�������Ԫ�ؾ�����			 
			} 
		}
		
		if(change==j+1)					//������������������˵�������Ѿ�����
			break;
	}
}
