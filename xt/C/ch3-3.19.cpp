#include <stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
 #define SElemType char
 #define true 1
 #define false 0
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
 
  int isValid(char ch[]) {
      
    SqStack stack;
    InitStack(&stack);
	char temp;
    for(int i=0;ch[i];i++)
    {
        if(ch[i]=='('||ch[i]=='{'||ch[i]=='[')
            
            Push(&stack,ch[i]); 
        else if(ch[i]==')'||ch[i]=='}'||ch[i]==']')
        {
            if(StackEmpty(stack))
            return false;
            
           Pop(&stack,&temp);
            switch (ch[i])
            {
                case ')':if(temp=='(') break;
                else return false;
                   
                case '}':if(temp=='{') break;
                else return false;
                    
                case ']':
                    if(temp=='[') break;
                    else return false;
                  
                
                
            }
        }

    }
  return StackEmpty(stack);
    }


int main(){
	char ch[]="(]";
	printf("%d",isValid(ch));
}
