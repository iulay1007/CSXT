#include <stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 2 /* �洢�ռ�������� */
 #define SElemType char
 #define true 1
 #define false 0
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
