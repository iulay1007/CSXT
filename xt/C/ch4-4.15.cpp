#include <stdio.h>
#include <string.h>
 #define MAXSTRLEN 40 /* �û�����255���ڶ�����󴮳���1���ֽڣ� */
 typedef char SString[MAXSTRLEN+1]; 
  /* bo4-1.c �����ö���˳��洢�ṹ(��c4-1.h����)�Ļ�������(14��) */
 /* SString�����飬�ʲ����������͡��˻������������㷨4.2,4.3,4.5 */
 int StrAssign(SString T,char *chars)
 { /* ����һ����ֵ����chars�Ĵ�T */
   int i;
   if(strlen(chars)>MAXSTRLEN)
     return 0;
   else
   {
     T[0]=strlen(chars);
     for(i=1;i<=T[0];i++)
       T[i]=*(chars+i-1);
     return 1;
   }
 }


