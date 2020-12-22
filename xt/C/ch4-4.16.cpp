#include <stdio.h>
#include <string.h>
 #define MAXSTRLEN 40 /* 用户可在255以内定义最大串长（1个字节） */
 typedef char SString[MAXSTRLEN+1]; 
  int StrCompare(SString S,SString T)
 { /* 初始条件: 串S和T存在 */
   /* 操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
   int i;
   for(i=1;i<=S[0]&&i<=T[0];++i)
     if(S[i]!=T[i])
       return S[i]-T[i];
   return S[0]-T[0];
 }

