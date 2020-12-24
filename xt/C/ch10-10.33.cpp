#include <stdio.h>
struct node * selectSort(struct node *head)
/*选择排序 链表 
*/
{
    struct node *head1,*max,*premax,*t,*pret;
    //head1：新链表的头指针；max：原链表中最大的结点；premax：最大结点的前驱结点；t：用于遍历原链表寻找最大结点;pret:t的前驱结点
    head1=NULL;
    while(head)//一遍遍地找原链表中当前最大结点 
    {
        max=head;
        premax=NULL;
        pret=head;
        t=head->next;
        //1、寻找最大结点 
        while(t){
            if(t->data>max->data){
                max=t;
                premax=pret;
            }
            pret=t;
            t=t->next;    
        }
        //2、让这个结点离开原链表
        if(max==head)//如果找到的结点是第一个结点
            head=head->next;//让头指针向后移一位就行
        else
            premax->next=max->next;
        //3、把此结点头插法插入新链表
        max->next=head1;
        head1=max;
    }
    return head1;
}
