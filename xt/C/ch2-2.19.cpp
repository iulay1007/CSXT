#include <stdio.h>
#include <malloc.h> 
typedef struct LNode {
    int data;
    LNode* next;

}LNode, * LinkList;
int InitList(LinkList* L)
{ /* �������������һ���յ����Ա�L */
    *L = (LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if (!*L) /* �洢����ʧ�� */
        return -1;
    (*L)->next = NULL; /* ָ����Ϊ�� */
    return 1;
}
int ListInsert(LinkList L, int i, int e) /* �㷨2.9�����ı�L */
{ /* �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
    int j = 0;
    LinkList p = L, s;
    while (p && j < i - 1) /* Ѱ�ҵ�i-1����� */
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) /* iС��1���ߴ��ڱ� */
        return -1;
    s = (LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
    s->data = e; /* ����L�� */
    s->next = p->next;
    p->next = s;
    return 1;
}
int ListTraverse(LinkList L)
/* vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ */
{ /* ��ʼ���������Ա�L�Ѵ��� */
  /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
    LinkList p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int DeleteNode(LinkList L, int mink, int maxk) {
    if (mink > maxk)
        return -1;
    LinkList head;
    LinkList tail;
    head = L->next;
   
    while (head->next!=NULL&&head->next->data < mink)
        head = head->next;
    tail = head;
    while (tail->next!=NULL&&tail->next->data < maxk)
        tail = tail->next;
    head->next = tail->next;

    return 1;
}
int main() {

    LinkList LA;
    InitList(&LA);
    for (int j = 5;j >= 1;j--)
    ListInsert(LA, 1, j*2);
   DeleteNode(LA, 3, 5);
    ListTraverse(LA);


    return 0;
}
