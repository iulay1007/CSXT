 /* c4-3.h ���Ŀ����洢��ʾ */
 #include <stdio.h>
 #include <string.h>
 #include <malloc.h>
 #define CHUNKSIZE 4 /* �����û�����Ŀ��С */
  char blank='#';
 typedef struct Chunk
 {
   char ch[CHUNKSIZE];
   struct Chunk *next;
 }Chunk;
 typedef struct
 {
   Chunk *head,*tail; /* ����ͷ��βָ�� */
   int curlen; /* ���ĵ�ǰ���� */
 }LString;
 
 void InitString(LString *T)
 { /* ��ʼ��(�����մ�)�ַ���T����� */
   (*T).curlen=0;
   (*T).head=NULL;
   (*T).tail=NULL;
 }
 int StrLength(LString S)
 { /* ����S��Ԫ�ظ���,��Ϊ���ĳ��� */
   return S.curlen;
 }

 
 int StrAssign(LString *T,char *chars)
 { /* ����һ����ֵ����chars�Ĵ�T(Ҫ��chars�в������������ַ�) */
   /* �ɹ�����OK�����򷵻�ERROR */
   int i,j,k,l;
   Chunk *p,*q;
   i=strlen(chars); /* iΪ���ĳ��� */
   if(!i||strchr(chars,blank)) /* ����Ϊ0��chars�а����������ַ� */
     return 0;
   (*T).curlen=i;
   j=i/CHUNKSIZE; /* jΪ�����Ľ���� */
   if(i%CHUNKSIZE)
     j++;
   for(k=0;k<j;k++)
   {
     p=(Chunk*)malloc(sizeof(Chunk));
     if(!p)
       return 0;
     if(k==0) /* ��һ������ */
       (*T).head=q=p;
     else
     {
       q->next=p;
       q=p;
     }
     for(l=0;l<CHUNKSIZE&&*chars;l++)
       *(q->ch+l)=*chars++;
     if(!*chars) /* ���һ������ */
     {
       (*T).tail=q;
       q->next=NULL;
       for(;l<CHUNKSIZE;l++) /* ���������ַ��������� */
         *(q->ch+l)=blank;
     }
   }
   return 1;
 }

 int StrCopy(LString *T,LString S)
 { /* ��ʼ����:��S���ڡ��������:�ɴ�S���Ƶô�T(���������ַ�һ�鿽��) */
   Chunk *h=S.head,*p,*q;
   (*T).curlen=S.curlen;
   if(h)
   {
     p=(*T).head=(Chunk*)malloc(sizeof(Chunk));
     *p=*h; /* ����1����� */
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
 { /* ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
   int i=0; /* iΪ��ǰ���Ƚ��ַ���S,T���е�λ�� */
   Chunk *ps=S.head,*pt=T.head; /* ps,pt�ֱ�ָ��S��T�Ĵ��ȽϿ� */
   int js=0,jt=0; /* js,jt�ֱ�ָʾS��T�Ĵ��Ƚ��ַ��ڿ��е�λ�� */
   while(i<S.curlen&&i<T.curlen)
   {
     i++; /* �ֱ���S��T�ĵ�i���ַ� */
     while(*(ps->ch+js)==blank) /* �����������ַ� */
     {
       js++;
       if(js==CHUNKSIZE)
       {
         ps=ps->next;
         js=0;
       }
     }; /* *(ps->ch+js)ΪS�ĵ�i����Ч�ַ� */
     while(*(pt->ch+jt)==blank) /* �����������ַ� */
     {
       jt++;
       if(jt==CHUNKSIZE)
       {
         pt=pt->next;
         jt=0;
       }
     }; /* *(pt->ch+jt)ΪT�ĵ�i����Ч�ַ� */
     if(*(ps->ch+js)!=*(pt->ch+jt))
       return *(ps->ch+js)-*(pt->ch+jt);
     else /* �����Ƚ���һ���ַ� */
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
 { /* ��T������S1��S2���Ӷ��ɵ��´� */
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
 { /* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
   /* ����,1��pos��StrLength(S)��0��len��StrLength(S)-pos+1 */
   Chunk *p,*q;
   int i,k,n,flag=1;
   if(pos<1||pos>S.curlen||len<0||len>S.curlen-pos+1)
     return 0;
   n=len/CHUNKSIZE; /* ���ɿյ�Sub�� */
   if(len%CHUNKSIZE)
     n++; /* nΪ��ĸ��� */
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
     *(p->ch+i)=blank; /* ���Subβ���Ķ���ռ� */
   q=(*Sub).head; /* qָ��Sub���������ƵĿ� */
   i=0; /* iָʾ�������Ƶ��ַ��ڿ��е�λ�� */
   p=S.head; /* pָ��S���ĵ�ǰ�� */
   n=0; /* nָʾ��ǰ�ַ��ڴ��е���� */
   while(flag)
   {
     for(k=0;k<CHUNKSIZE;k++) /* kָʾ��ǰ�ַ��ڿ��е�λ�� */
       if(*(p->ch+k)!=blank)
       {
         n++;
         if(n>=pos&&n<=pos+len-1) /* ���� */
         {
           if(i==CHUNKSIZE)
           { /* ����һ�� */
             q=q->next;
             i=0;
           }
           *(q->ch+i)=*(p->ch+k);
           i++;
           if(n==pos+len-1) /* ���ƽ��� */
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
 { /* 1��pos��StrLength(S)+1���ڴ�S�ĵ�pos���ַ�֮ǰ���봮T */
   int i,j,k;
   Chunk *p,*q;
   LString t;
   if(pos<1||pos>StrLength(*S)+1) /* pos������Χ */
     return 0;
   StrCopy(&t,T); /* ����TΪt */
   i=(pos-1)/CHUNKSIZE; /* ��������Ҫ�ƶ��Ŀ��� */
   j=(pos-1)%CHUNKSIZE; /* �������������һ����Ҫ�ƶ����ַ��� */
   p=(*S).head;
   if(pos==1) /* ����S��ǰ */
   {
     t.tail->next=(*S).head;
     (*S).head=t.head;
   }
   else if(j==0) /* ���ڿ�֮�� */
   {
     for(k=1;k<i;k++)
       p=p->next; /* pָ���������� */
     q=p->next; /* qָ��������ҿ� */
     p->next=t.head; /* ����t */
     t.tail->next=q;
     if(q==NULL) /* ����S���� */
       (*S).tail=t.tail; /* �ı�βָ�� */
   }
   else /* ����һ���ڵ������ַ�֮�� */
   {
     for(k=1;k<=i;k++)
       p=p->next; /* pָ���������ڿ� */
     q=(Chunk*)malloc(sizeof(Chunk)); /* �����¿� */
     for(i=0;i<j;i++)
       *(q->ch+i)=blank; /* ��q��ǰj���ַ�Ϊ�������ַ� */
     for(i=j;i<CHUNKSIZE;i++)
     {
       *(q->ch+i)=*(p->ch+i); /* ���Ʋ�������ַ���q */
       *(p->ch+i)=blank; /* p�ĸ��ַ�Ϊ�������ַ� */
     }
     q->next=p->next;
     p->next=t.head;
     t.tail->next=q;
   }
   (*S).curlen+=t.curlen;
  
   return 1;
 }
 int Index(LString S,LString T,int pos)
 { /* TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ�, */
   /* �򷵻ص�һ���������Ӵ���S�е�λ��,���򷵻�0 */
   int i,n,m;
   LString sub;
   if(pos>=1&&pos<=StrLength(S)) /* pos�������� */
   {
     n=StrLength(S); /* �������� */
     m=StrLength(T); /* T������ */
     i=pos;
     while(i<=n-m+1)
     {
       SubString(&sub,S,i,m); /* subΪ��S�ĵ�i���ַ���,����Ϊm���Ӵ� */
       if(StrCompare(sub,T)!=0) /* sub������T */
         ++i;
       else
         return i;
     }
   }
   return 0;
 }

  void StrPrint(LString T)
 { /* ����ַ���T����� */
   int i=0,j;
   Chunk *h;
   h=T.head;
   while(i<T.curlen)
   {
     for(j=0;j<CHUNKSIZE;j++)
       if(*(h->ch+j)!=blank) /* �����������ַ� */
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
   printf(" ����=%d\n",StrLength(t1));
   k=StrAssign(&t1,s3);
   if(k==1)
   {
     printf("��t1Ϊ: ");
   }
   else
     printf("����\n"); /* �������ɿմ� */
   k=StrAssign(&t1,s4);
   if(k==1)
   {
     printf("��t1Ϊ: ");
     StrPrint(t1);
   }
   else
     printf("����\n"); /* �������ɺ��б���blank��������ַ��Ĵ� */
   k=StrAssign(&t1,s1);
   if(k==1)
   {
     printf("��t1Ϊ: ");
     StrPrint(t1);
   }
   else
     printf("����\n");
   printf(" ����=%d\n",StrLength(t1));
   StrAssign(&t2,s2);
   printf("��t2Ϊ: ");
   StrCopy(&t3,t1);
   printf("�ɴ�t1�����õ���t3,��t3Ϊ: ");
   StrPrint(t3);
   InitString(&t4);
   StrAssign(&t4,s5);
  Concat(&t1,t2,t3);
   printf("��t1(=t2+t3)Ϊ: ");
 
   SubString(&t2,t1,pos,len);
   printf("��t2Ϊ: ");
 
   printf("StrCompare(t1,t2)=%d\n",StrCompare(t1,t2));
   printf("ɾ����t1�е����ַ������ӵ�pos���ַ���ɾ��len���ַ���������pos,len��");
   
   return 0;
 }

