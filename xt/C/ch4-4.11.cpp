#include <stdio.h>
#include <string.h>
 #define MAXSTRLEN 40 /* 用户可在255以内定义最大串长（1个字节） */
 typedef char SString[MAXSTRLEN+1]; 
  /* bo4-1.c 串采用定长顺序存储结构(由c4-1.h定义)的基本操作(14个) */
 /* SString是数组，故不需引用类型。此基本操作包括算法4.2,4.3,4.5 */
 int StrAssign(SString T,char *chars)
 { /* 生成一个其值等于chars的串T */
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
 { /* 初始条件: 串S和T存在 */
   /* 操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
   int i;
   for(i=1;i<=S[0]&&i<=T[0];++i)
     if(S[i]!=T[i])
       return S[i]-T[i];
   return S[0]-T[0];
 }

 int StrLength(SString S)
 { /* 返回串的元素个数 */
   return S[0];
 }


 int Concat(SString T,SString S1,SString S2) /* 算法4.2改 */
 { /* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
   int i;
   if(S1[0]+S2[0]<=MAXSTRLEN)
   { /* 未截断 */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=S2[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=S1[0]+S2[0];
     return 1;
   }
   else
   { /* 截断S2 */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=MAXSTRLEN-S1[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=MAXSTRLEN;
     return 0;
   }
 }

 int SubString(SString Sub,SString S,int pos,int len)
 { /* 用Sub返回串S的第pos个字符起长度为len的子串。算法4.3 */
   int i;
   if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
     return 0;
   for(i=1;i<=len;i++)
     Sub[i]=S[pos+i-1];
   Sub[0]=len;
   return 1;
 }
 
 //假设只有数字字符和英文字符
 //利用桶排序的思想
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
