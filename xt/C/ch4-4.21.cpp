 /* c4-3.h 串的块链存储表示 */
 #include <stdio.h>
 #include <string.h>
 #include <malloc.h>
 #define CHUNKSIZE 4 /* 可由用户定义的块大小 */
  char blank='#';
 typedef struct Chunk
 {
   char ch[CHUNKSIZE];
   struct Chunk *next;
 }Chunk;
 typedef struct
 {
   Chunk *head,*tail; /* 串的头和尾指针 */
   int curlen; /* 串的当前长度 */
 }LString;
 
 void InitString(LString *T)
 { /* 初始化(产生空串)字符串T。另加 */
   (*T).curlen=0;
   (*T).head=NULL;
   (*T).tail=NULL;
 }
 int StrLength(LString S)
 { /* 返回S的元素个数,称为串的长度 */
   return S.curlen;
 }

 
 int StrAssign(LString *T,char *chars)
 { /* 生成一个其值等于chars的串T(要求chars中不包含填补空余的字符) */
   /* 成功返回OK，否则返回ERROR */
   int i,j,k,l;
   Chunk *p,*q;
   i=strlen(chars); /* i为串的长度 */
   if(!i||strchr(chars,blank)) /* 串长为0或chars中包含填补空余的字符 */
     return 0;
   (*T).curlen=i;
   j=i/CHUNKSIZE; /* j为块链的结点数 */
   if(i%CHUNKSIZE)
     j++;
   for(k=0;k<j;k++)
   {
     p=(Chunk*)malloc(sizeof(Chunk));
     if(!p)
       return 0;
     if(k==0) /* 第一个链块 */
       (*T).head=q=p;
     else
     {
       q->next=p;
       q=p;
     }
     for(l=0;l<CHUNKSIZE&&*chars;l++)
       *(q->ch+l)=*chars++;
     if(!*chars) /* 最后一个链块 */
     {
       (*T).tail=q;
       q->next=NULL;
       for(;l<CHUNKSIZE;l++) /* 用填补空余的字符填满链表 */
         *(q->ch+l)=blank;
     }
   }
   return 1;
 }

 int StrCopy(LString *T,LString S)
 { /* 初始条件:串S存在。操作结果:由串S复制得串T(连填补空余的字符一块拷贝) */
   Chunk *h=S.head,*p,*q;
   (*T).curlen=S.curlen;
   if(h)
   {
     p=(*T).head=(Chunk*)malloc(sizeof(Chunk));
     *p=*h; /* 复制1个结点 */
     h=h->next;
     while(h)
     {
       q=p;
       p=(Chunk*)malloc(sizeof(Chunk));
       q->next=p;
       *p=*h;
       h=h->next;
     }
     p->next=NULL;
     (*T).tail=p;
     return 1;
   }
   else
    return 0;
 }

int StrCompare(LString S,LString T)
 { /* 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
   int i=0; /* i为当前待比较字符在S,T串中的位置 */
   Chunk *ps=S.head,*pt=T.head; /* ps,pt分别指向S和T的待比较块 */
   int js=0,jt=0; /* js,jt分别指示S和T的待比较字符在块中的位序 */
   while(i<S.curlen&&i<T.curlen)
   {
     i++; /* 分别找S和T的第i个字符 */
     while(*(ps->ch+js)==blank) /* 跳过填补空余的字符 */
     {
       js++;
       if(js==CHUNKSIZE)
       {
         ps=ps->next;
         js=0;
       }
     }; /* *(ps->ch+js)为S的第i个有效字符 */
     while(*(pt->ch+jt)==blank) /* 跳过填补空余的字符 */
     {
       jt++;
       if(jt==CHUNKSIZE)
       {
         pt=pt->next;
         jt=0;
       }
     }; /* *(pt->ch+jt)为T的第i个有效字符 */
     if(*(ps->ch+js)!=*(pt->ch+jt))
       return *(ps->ch+js)-*(pt->ch+jt);
     else /* 继续比较下一个字符 */
     {
       js++;
       if(js==CHUNKSIZE)
       {
         ps=ps->next;
         js=0;
       }
       jt++;
       if(jt==CHUNKSIZE)
       {
         pt=pt->next;
         jt=0;
       }
     }
   }
   return S.curlen-T.curlen;
 }
 
 
 
 int Concat(LString *T,LString S1,LString S2)
 { /* 用T返回由S1和S2联接而成的新串 */
   LString a1,a2;
   InitString(&a1);
   InitString(&a2);
   StrCopy(&a1,S1);
   StrCopy(&a2,S2);
   (*T).curlen=S1.curlen+S2.curlen;
   (*T).head=a1.head;
   a1.tail->next=a2.head;
   (*T).tail=a2.tail;
   return 1;
 }
 
 
 int SubString(LString *Sub, LString S,int pos,int len)
 { /* 用Sub返回串S的第pos个字符起长度为len的子串。 */
   /* 其中,1≤pos≤StrLength(S)且0≤len≤StrLength(S)-pos+1 */
   Chunk *p,*q;
   int i,k,n,flag=1;
   if(pos<1||pos>S.curlen||len<0||len>S.curlen-pos+1)
     return 0;
   n=len/CHUNKSIZE; /* 生成空的Sub串 */
   if(len%CHUNKSIZE)
     n++; /* n为块的个数 */
   p=(Chunk*)malloc(sizeof(Chunk));
   (*Sub).head=p;
   for(i=1;i<n;i++)
   {
     q=(Chunk*)malloc(sizeof(Chunk));
     p->next=q;
     p=q;
   }
   p->next=NULL;
   (*Sub).tail=p;
   (*Sub).curlen=len;
   for(i=len%CHUNKSIZE;i<CHUNKSIZE;i++)
     *(p->ch+i)=blank; /* 填充Sub尾部的多余空间 */
   q=(*Sub).head; /* q指向Sub串即将复制的块 */
   i=0; /* i指示即将复制的字符在块中的位置 */
   p=S.head; /* p指向S串的当前块 */
   n=0; /* n指示当前字符在串中的序号 */
   while(flag)
   {
     for(k=0;k<CHUNKSIZE;k++) /* k指示当前字符在块中的位置 */
       if(*(p->ch+k)!=blank)
       {
         n++;
         if(n>=pos&&n<=pos+len-1) /* 复制 */
         {
           if(i==CHUNKSIZE)
           { /* 到下一块 */
             q=q->next;
             i=0;
           }
           *(q->ch+i)=*(p->ch+k);
           i++;
           if(n==pos+len-1) /* 复制结束 */
           {
             flag=0;
             break;
           }
         }
       }
     p=p->next;
   }
   return 1;
 }
 
 int StrInsert(LString *S,int pos,LString T)
 { /* 1≤pos≤StrLength(S)+1。在串S的第pos个字符之前插入串T */
   int i,j,k;
   Chunk *p,*q;
   LString t;
   if(pos<1||pos>StrLength(*S)+1) /* pos超出范围 */
     return 0;
   StrCopy(&t,T); /* 复制T为t */
   i=(pos-1)/CHUNKSIZE; /* 到达插入点要移动的块数 */
   j=(pos-1)%CHUNKSIZE; /* 到达插入点在最后一块上要移动的字符数 */
   p=(*S).head;
   if(pos==1) /* 插在S串前 */
   {
     t.tail->next=(*S).head;
     (*S).head=t.head;
   }
   else if(j==0) /* 插在块之间 */
   {
     for(k=1;k<i;k++)
       p=p->next; /* p指向插入点的左块 */
     q=p->next; /* q指向插入点的右块 */
     p->next=t.head; /* 插入t */
     t.tail->next=q;
     if(q==NULL) /* 插在S串后 */
       (*S).tail=t.tail; /* 改变尾指针 */
   }
   else /* 插在一块内的两个字符之间 */
   {
     for(k=1;k<=i;k++)
       p=p->next; /* p指向插入点所在块 */
     q=(Chunk*)malloc(sizeof(Chunk)); /* 生成新块 */
     for(i=0;i<j;i++)
       *(q->ch+i)=blank; /* 块q的前j个字符为填补空余的字符 */
     for(i=j;i<CHUNKSIZE;i++)
     {
       *(q->ch+i)=*(p->ch+i); /* 复制插入点后的字符到q */
       *(p->ch+i)=blank; /* p的该字符为填补空余的字符 */
     }
     q->next=p->next;
     p->next=t.head;
     t.tail->next=q;
   }
   (*S).curlen+=t.curlen;
  
   return 1;
 }
 int Index(LString S,LString T,int pos)
 { /* T为非空串。若主串S中第pos个字符之后存在与T相等的子串, */
   /* 则返回第一个这样的子串在S中的位置,否则返回0 */
   int i,n,m;
   LString sub;
   if(pos>=1&&pos<=StrLength(S)) /* pos满足条件 */
   {
     n=StrLength(S); /* 主串长度 */
     m=StrLength(T); /* T串长度 */
     i=pos;
     while(i<=n-m+1)
     {
       SubString(&sub,S,i,m); /* sub为从S的第i个字符起,长度为m的子串 */
       if(StrCompare(sub,T)!=0) /* sub不等于T */
         ++i;
       else
         return i;
     }
   }
   return 0;
 }

  void StrPrint(LString T)
 { /* 输出字符串T。另加 */
   int i=0,j;
   Chunk *h;
   h=T.head;
   while(i<T.curlen)
   {
     for(j=0;j<CHUNKSIZE;j++)
       if(*(h->ch+j)!=blank) /* 不是填补空余的字符 */
       {
         printf("%c",*(h->ch+j));
         i++;
       }
     h=h->next;
   }
   printf("\n");
 }
 
 int main()
 {
   char *s1="ABCDEFGHI",*s2="12345",*s3="",*s4="asd#tr",*s5="ABCD";
   int k;
   int pos,len;
   LString t1,t2,t3,t4;
   InitString(&t1);
   InitString(&t2);
   printf(" 串长=%d\n",StrLength(t1));
   k=StrAssign(&t1,s3);
   if(k==1)
   {
     printf("串t1为: ");
   }
   else
     printf("出错\n"); /* 不能生成空串 */
   k=StrAssign(&t1,s4);
   if(k==1)
   {
     printf("串t1为: ");
     StrPrint(t1);
   }
   else
     printf("出错\n"); /* 不能生成含有变量blank所代表的字符的串 */
   k=StrAssign(&t1,s1);
   if(k==1)
   {
     printf("串t1为: ");
     StrPrint(t1);
   }
   else
     printf("出错\n");
   printf(" 串长=%d\n",StrLength(t1));
   StrAssign(&t2,s2);
   printf("串t2为: ");
   StrCopy(&t3,t1);
   printf("由串t1拷贝得到串t3,串t3为: ");
   StrPrint(t3);
   InitString(&t4);
   StrAssign(&t4,s5);
  Concat(&t1,t2,t3);
   printf("串t1(=t2+t3)为: ");
 
   SubString(&t2,t1,pos,len);
   printf("串t2为: ");
 
   printf("StrCompare(t1,t2)=%d\n",StrCompare(t1,t2));
   printf("删除串t1中的子字符串：从第pos个字符起删除len个字符。请输入pos,len：");
   
   return 0;
 }

