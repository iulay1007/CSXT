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



 int StrCompare(SString S,SString T)
 { /* ��ʼ����: ��S��T���� */
   /* �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
   int i;
   for(i=1;i<=S[0]&&i<=T[0];++i)
     if(S[i]!=T[i])
       return S[i]-T[i];
   return S[0]-T[0];
 }

 int StrLength(SString S)
 { /* ���ش���Ԫ�ظ��� */
   return S[0];
 }


 int Concat(SString T,SString S1,SString S2) /* �㷨4.2�� */
 { /* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
   int i;
   if(S1[0]+S2[0]<=MAXSTRLEN)
   { /* δ�ض� */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=S2[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=S1[0]+S2[0];
     return 1;
   }
   else
   { /* �ض�S2 */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=MAXSTRLEN-S1[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=MAXSTRLEN;
     return 0;
   }
 }

 int SubString(SString Sub,SString S,int pos,int len)
 { /* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ����㷨4.3 */
   int i;
   if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
     return 0;
   for(i=1;i<=len;i++)
     Sub[i]=S[pos+i-1];
   Sub[0]=len;
   return 1;
 }
 int reverseStr(SString S){
	int p=1;
	int q=S[0]-'0';
	int temp;
	while(p<q)
	{
	temp=S[p];
	S[p]=S[q];
	S[q]=temp;
	p++;
	q--;	
	}
	
 	
	return 1;
 	
 }
 int main(){
 	SString S="4abcd";
 	reverseStr(S);
 	for(int i=1;i<=S[0]-'0';i++)
 	printf("%c",S[i]);
 	
 	return 0;
 }

 
