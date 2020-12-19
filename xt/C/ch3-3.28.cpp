#include<stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
 #define SElemType char
 typedef struct SqStack
 {
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack;
 
 int InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     return -1; /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 1;
 }
 int StackLength(SqStack S)
 { /* 返回S的元素个数，即栈的长度 */
   return S.top-S.base;
 }

 int GetTop(SqStack S,SElemType *e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 1;
   }
   else
     return 0;
 }

 int Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
      return -1; /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 1;
 }

 int Pop(SqStack *S,SElemType *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
   if((*S).top==(*S).base)
     return 0;
   *e=*--(*S).top;
   return 1;
 }
 
  int StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return 1;
   else
     return 0;
 }


int prio(char op) {                 //给运算符优先级排序
    int priority;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    return priority;
}
bool Trans(char str[],char str1[]) {   //引用传递
   	SqStack s;
 	InitStack(&s);                 //定义一个char类型的栈s
    int i;
    int j=0;
    char temp;
    for (i = 0; str[i]!='\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {    //如果是数字，直接入栈
            str1[j]=str[i];
            j++;
        }
        else {                        //否则不是数字
            if (StackEmpty(s))            //栈空则入站
                Push(&s,str[i]);
            else if (str[i] == '(')   //左括号入栈
                 Push(&s,str[i]);
            else if (str[i] == ')') {  //如果是右括号，只要栈顶不是左括号，就弹出并输出
            GetTop(s,&temp);
                while (temp != '(') {  
                    str1[j]= temp;
                    j++;
                    Pop(&s,&temp);
                }
               Pop(&s,&temp);                //弹出左括号，但不输出
            }
            else {
            	GetTop(s,&temp);
                while (prio(str[i]) <= prio(temp)) { //栈顶优先级大于等于当前运算符，则输出
                    str1[j]= temp;
                    j++;
                    Pop(&s,&temp);
                    if (StackEmpty(s))      //栈为空，停止
                        break;
                }
               Push(&s,str[i]);  //把当前运算符入栈
            }
        }
    }
    while (StackEmpty(s)==0) {      //最后，如果栈不空，则弹出所有元素并输出
        GetTop(s,&temp);
		str1[j]= temp;
		j++; 
     	Pop(&s,&temp);
    }
    return 1;
}
int main() {                //主程序
    char ch[]="1+2*4";
    char ch1[100];
   
    Trans(ch,ch1);
    for(int i=0;i<6;i++)
    printf("%c",ch1[i]);
    return 0;
}
