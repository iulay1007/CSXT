 #include <stdio.h>
 #include <malloc.h>
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
 
int CopyGList(GList *T,GList L)
 { /* ����ͷβ����洢�ṹ,�ɹ����L���Ƶõ������T�� */
   if(!L) /* ���ƿձ� */
     *T=NULL;
   else
   {
     *T=(GList)malloc(sizeof(GLNode)); /* ������ */
     (*T)->tag=L->tag;
     if(L->tag==ATOM)
       (*T)->a.atom=L->a.atom; /* ���Ƶ�ԭ�� */
     else	//�ӱ�ʱ 
     {
     	//�ݹ� 
       CopyGList(&((*T)->a.ptr.hp),L->a.ptr.hp);
       CopyGList(&((*T)->a.ptr.tp),L->a.ptr.tp);
  
     }
   }
   return 1;
 }
