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
 
int InsertSort(SqList &L)
 { /* ��˳���L��ֱ�Ӳ��������㷨10.1 */
   int i,j,k;
   k=L.length;
   for(i=k-1;i>=1;i--)
     if (L.r[i+1].key<L.r[i].key) /* "<",�轫L.r[i]���������ӱ� */
     {
       L.r[k+1]=L.r[i]; /* ����Ϊ�ڱ� */
       for(j=i-1;(L.r[j+1].key<L.r[k+1].key);j++)
	 L.r[j]=L.r[j+1]; /* ��¼���� */
       L.r[j]=L.r[k+1]; /* ���뵽��ȷλ�� */
     }
     return 0;
 }
