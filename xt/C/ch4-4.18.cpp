#include <stdio.h>
#define MAXSTRLEN 40 /* 用户可在255以内定义最大串长（1个字节） */
 typedef char SString[MAXSTRLEN+1]; 
int countChar(SString S){
	int ch[256]={0};
	for(int i=1;i<=S[0]-'0';i++){
	ch[S[i]]++;
}

	for(int i=0;i<256;i++)
	{
		if(ch[i]>0){
	printf("%c ",i);
	printf("%d  \n",ch[i]);
}
}
} 

int main(){
	
	SString s="3qwq"; 
	countChar(s);
	return 0;
}


