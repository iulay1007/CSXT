#include<stdio.h>
//���Ķ���˳��洢��ʾ
#define MAXSTRLEN 50  // // �û�����50���ڶ�����󴮳�
typedef unsigned char SString[MAXSTRLEN + 1];//0�ŵ�Ԫ��Ŵ��ĳ���
 
//�����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ�����ֵΪ0�����У�T�ǿգ�1<=pos<=StrLength(S)��
int indexBF(SString S, SString T, int pos){
	int i = pos, j = 1;
	while(i <= S[0] && j <= T[0]){
		if(S[i] == T[j]){
			i++;
			j++;
		}else{
			i = i - j + 2;//i�ص�ԭλ����i - j + 1 ,����i�˵�Զλ�õ���һ��λ����i - j + 1 + 1
			j = 1;
		}
	}
	if(j > T[0]){//���j > len(T)��˵��ģʽ��T��S��ĳ�Ӵ���ȫƥ��
		return i - T[0];//��Ϊi���Ѿ�������һ���ˣ�������i-len(T)������i-len(T)+1
	}else
		return 0;
}
 
void init(SString &S, char str[]){
	int i = 0;
	while(str[i]!='\0'){
		S[i+1] = str[i];
		i++;
	}
	S[i+1] = '\0';
	S[0] = i;
}
 
void printStr(SString Str){
	for(int i = 1; i <= Str[0]; i++){
		printf("%c", Str[i]);
	}
	printf("\n");
}
 
int main(){
	SString S ;
	init(S, "ababcabcacbab");
	printStr(S);
 
	SString T;
	init(T, "abcac");
	printStr(T);
 
	int index = indexBF(S, T, 1);
	printf("index is %d\n", index);
 
    return 0;
}
