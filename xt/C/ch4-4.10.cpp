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

 
