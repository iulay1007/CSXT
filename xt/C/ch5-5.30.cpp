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
 
int GListDepth(GList L)
 { /* 采用头尾链表存储结构,求广义表L的深度。算法5.5 */
   int max,dep;
   GList pp;
   if(!L)
     return 1; /* 空表深度为1 */
   if(L->tag==ATOM)
     return 0; /* 原子深度为0 */
   for(max=0,pp=L;pp;pp=pp->a.ptr.tp)
   {
     dep=GListDepth(pp->a.ptr.hp); /* 求以pp->a.ptr.hp为头指针的子表深度 */
     if(dep>max)
       max=dep;
   }
   return max+1; /* 非空表的深度是各元素的深度的最大值加1 */
 }
