#include <stdio.h>
#include <string.h>
 #define MAXSTRLEN 40 /* �û�����255���ڶ�����󴮳���1���ֽڣ� */
 typedef char SString[MAXSTRLEN+1]; 
  int StrCompare(SString S,SString T)
 { /* ��ʼ����: ��S��T���� */
   /* �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
   int i;
   for(i=1;i<=S[0]&&i<=T[0];++i)
     if(S[i]!=T[i])
       return S[i]-T[i];
   return S[0]-T[0];
 }

