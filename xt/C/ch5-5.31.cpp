 #include <stdio.h>
 #include <malloc.h>
 typedef enum{ATOM,LIST}ElemTag; /* ATOM==0:原子,LIST==1:子表 */
 typedef struct GLNode
 {
   ElemTag tag; /* 公共部分,用于区分原子结点和表结点 */
   union /* 原子结点和表结点的联合部分 */
   {
     int atom; /* atom是原子结点的值域,AtomType由用户定义 */
     struct
     {
       struct GLNode *hp,*tp;
     }ptr; /* ptr是表结点的指针域,prt.hp和ptr.tp分别指向表头和表尾 */
   }a;
 }*GList,GLNode; /* 广义表类型 */
 
int CopyGList(GList *T,GList L)
 { /* 采用头尾链表存储结构,由广义表L复制得到广义表T。 */
   if(!L) /* 复制空表 */
     *T=NULL;
   else
   {
     *T=(GList)malloc(sizeof(GLNode)); /* 建表结点 */
     (*T)->tag=L->tag;
     if(L->tag==ATOM)
       (*T)->a.atom=L->a.atom; /* 复制单原子 */
     else	//子表时 
     {
     	//递归 
       CopyGList(&((*T)->a.ptr.hp),L->a.ptr.hp);
       CopyGList(&((*T)->a.ptr.tp),L->a.ptr.tp);
  
     }
   }
   return 1;
 }
