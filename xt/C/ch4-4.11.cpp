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
 
 //����ֻ�������ַ���Ӣ���ַ�
 //����Ͱ�����˼��
 int putStr(SString s,SString t){
 	int ch[62]; 
 	for(int i=1;i<=s[0]-'0';i++)
 	{
 		if(s[i]>='0'&&s[i]<='9')
 		{
		 ch[s[i]-'0']=1;
	//	 printf("%d",s[i]-'0');
		 }
 		else if(s[i]>='A'&&s[i]<='Z')
 		{
		 ch[s[i]-55]=1;
		// printf("%c",s[i]-55);
		 }
		 else if(s[i]>='a'&&s[i]<='z')
		 {
		 ch[s[i]-77]=1;
		// printf("%d",s[i]-77);
		 }
	 } 
	 
	 for(int i=1;i<=t[0]-'0';i++)
	 {
	 	if(t[i]>='0'&&t[i]<='9'&&ch[t[i]-'0']==1)
	 	ch[t[i]-'0']=0;
	 	else if(t[i]>='A'&&t[i]<='Z'&&ch[t[i]-55]==1)
	 	ch[t[i]-55]=0;
	 	else if(t[i]>='a'&&t[i]<='z'&&ch[t[i]-77]==1)
	 	ch[t[i]-77]=0;
	 }
	 
	for(int i=0;i<10;i++)
	 if(ch[i]==1)
	 printf("%c",i);
	 for(int i=10;i<36;i++)
	 if(ch[i]==1)
	 printf("%c",i+55);
	 for(int i=36;i<62;i++)
	 if(ch[i]==1)
	 printf("%c",i+77);
	 
 } 
 
 int main(){
 	SString s="4qBRY";
 	SString t="2AB";
 	putStr(s,t);
	 return 0; 
 }
