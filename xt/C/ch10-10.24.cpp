/*
2·��������
2·���������۰����Ļ����Ͻ��иĽ���
�۰������ԭ��ֱ�Ӳ���Ļ����ϸĽ���ͨ���۰���ң��Խ��ٵıȽϴ������ҵ���Ҫ�����λ�ã������ڲ���Ĺ�������Ȼû�м����ƶ�����������2·�����ڴ˻����ϸĽ����������ƶ�������������Ȼ��û�б����ƶ���¼�����Ҫ����Ļ����ǵøı�洢�ṹ��
��ô��μ��ٵ��ƶ�����������
�����һ������{2, 7, 8,10,15 ,29,30, 40,50,66,70,80}���������9����ô���ճ�����۰���Һ���Ҫ�ƶ���¼9�Σ�������Ϊ����ֻ�ܹ���һ�������ϲ��롣
��������趨һ����������A����С��ԭ��������ͬ�Ĵ�С����A[0]��Ϊ��һ��ԭ�����һ������ͨ������first��finalָ�������������е���Сֵ�����ֵ����Ϊ���е�β����ͷ�������ҽ�������λһ��ѭ�����飬�����Ϳ��Խ���˫�˲��롣��ʱԭ����ֻ��������ƶ�3�Ρ�

֮�����ܼ����ƶ�������ԭ�����ڿ�����2�������ƶ���¼���ʳ�Ϊ2·���롣
A[0]��ǰ���Ǹ��������У�����Ҳ���������У�����Ҳ����������

�������˼·��
1.��ԭ�����һ��Ԫ�ظ�ֵ��A[0],��Ϊ��־Ԫ��
2.��˳�����β���ʣ�µ�ԭ�����Ԫ��

��������Ԫ�����һ�����бȽϣ�ټ����A[0],�����A[0]ǰ����������У��������������������
��ǰ����������л������������н����۰����
���ҵ�����λ�ú���м�¼���ƶ����ֱ���first����ǰ�ƺ���final�����ƶ�
�����¼
3.������õ�A��������ݴ�first��final��������ֵ��ԭ���顣
*/
void TwoPathInsertSort(SqList *L)
 { /* 2_·�������� */
   int i,j,first,final;
   int *d;
   d=(int*)malloc((*L).length*sizeof(int)); /* ����L.length����¼����ʱ�ռ� */
   d[0]=(*L).r[1]; /* ��L�ĵ�1����¼Ϊd���ź���ļ�¼(��λ��[0]) */
   first=final=0; /* first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������1����¼��λ�� */
   for(i=2;i<=(*L).length;++i)
   { /* ���ν�L�ĵ�2�������1����¼����d�� */
     if((*L).r[i].key<d[first].key)
     { /* �����¼С��d����Сֵ���嵽d[first]֮ǰ(�����ƶ�d�����Ԫ��) */
       first=(first-1+(*L).length)%(*L).length; 
       d[first]=(*L).r[i];
     }
     else if((*L).r[i].key>d[final].key)
     { /* �����¼����d�����ֵ���嵽d[final]֮��(�����ƶ�d�����Ԫ��) */
       final=final+1;
       d[final]=(*L).r[i];
     }
     else
     { /* �����¼����d����Сֵ��С��d�����ֵ���嵽d���м�(��Ҫ�ƶ�d�����Ԫ��) */
       j=final++; /* �ƶ�d��β��Ԫ���Ա㰴������¼ */
       while((*L).r[i].key<d[j].key)
       {
         d[(j+1)%(*L).length]=d[j];
         j=(j-1+(*L).length)%(*L).length;
       }
       d[j+1]=(*L).r[i];
     }
   }
   for(i=1;i<=(*L).length;i++) /* ��d����L.r */
     (*L).r[i]=d[(i+first-1)%(*L).length]; 
 }
