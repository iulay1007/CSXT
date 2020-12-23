 typedef enum{ATOM,LIST}ElemTag; /* ATOM==0:ԭ��,LIST==1:�ӱ� */
 typedef struct GLNode
 {
   ElemTag tag; /* ��������,��������ԭ�ӽ��ͱ��� */
   union /* ԭ�ӽ��ͱ�������ϲ��� */
   {
     int atom; /* atom��ԭ�ӽ���ֵ��,AtomType���û����� */
     struct
     {
       struct GLNode *hp,*tp;
     }ptr; /* ptr�Ǳ����ָ����,prt.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β */
   }a;
 }*GList,GLNode; /* ��������� */
 
int GListDepth(GList L)
 { /* ����ͷβ����洢�ṹ,������L����ȡ��㷨5.5 */
   int max,dep;
   GList pp;
   if(!L)
     return 1; /* �ձ����Ϊ1 */
   if(L->tag==ATOM)
     return 0; /* ԭ�����Ϊ0 */
   for(max=0,pp=L;pp;pp=pp->a.ptr.tp)
   {
     dep=GListDepth(pp->a.ptr.hp); /* ����pp->a.ptr.hpΪͷָ����ӱ���� */
     if(dep>max)
       max=dep;
   }
   return max+1; /* �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1 */
 }
