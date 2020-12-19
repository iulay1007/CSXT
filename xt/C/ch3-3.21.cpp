#include<stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 2 /* �洢�ռ�������� */
 #define SElemType char
 typedef struct SqStack
 {
   SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   SElemType *top; /* ջ��ָ�� */
   int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
 }SqStack;
 
 int InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     return -1; /* �洢����ʧ�� */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 1;
 }
 int StackLength(SqStack S)
 { /* ����S��Ԫ�ظ�������ջ�ĳ��� */
   return S.top-S.base;
 }

 int GetTop(SqStack S,SElemType *e)
 { /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 1;
   }
   else
     return 0;
 }

 int Push(SqStack *S,SElemType e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
      return -1; /* �洢����ʧ�� */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 1;
 }

 int Pop(SqStack *S,SElemType *e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if((*S).top==(*S).base)
     return 0;
   *e=*--(*S).top;
   return 1;
 }
 
  int StackEmpty(SqStack S)
 { /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
   if(S.top==S.base)
     return 1;
   else
     return 0;
 }


int prio(char op) {                 //����������ȼ�����
    int priority;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    return priority;
}
bool Trans(char str[],char str1[]) {   //���ô���
   	SqStack s;
 	InitStack(&s);                 //����һ��char���͵�ջs
    int i;
    int j=0;
    char temp;
    for (i = 0; str[i]!='\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {    //��������֣�ֱ����ջ
            str1[j]=str[i];
            j++;
        }
        else {                        //����������
            if (StackEmpty(s))            //ջ������վ
                Push(&s,str[i]);
            else if (str[i] == '(')   //��������ջ
                 Push(&s,str[i]);
            else if (str[i] == ')') {  //����������ţ�ֻҪջ�����������ţ��͵��������
            GetTop(s,&temp);
                while (temp != '(') {  
                    str1[j]= temp;
                    j++;
                    Pop(&s,&temp);
                }
               Pop(&s,&temp);                //���������ţ��������
            }
            else {
            	GetTop(s,&temp);
                while (prio(str[i]) <= prio(temp)) { //ջ�����ȼ����ڵ��ڵ�ǰ������������
                    str1[j]= temp;
                    j++;
                    Pop(&s,&temp);
                    if (StackEmpty(s))      //ջΪ�գ�ֹͣ
                        break;
                }
               Push(&s,str[i]);  //�ѵ�ǰ�������ջ
            }
        }
    }
    while (StackEmpty(s)==0) {      //������ջ���գ��򵯳�����Ԫ�ز����
        GetTop(s,&temp);
		str1[j]= temp;
		j++; 
     	Pop(&s,&temp);
    }
    return 1;
}
int main() {                //������
    char ch[]="1+2*4";
    char ch1[100];
   
    Trans(ch,ch1);
    for(int i=0;i<6;i++)
    printf("%c",ch1[i]);
    return 0;
}
