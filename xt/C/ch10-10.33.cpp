#include <stdio.h>
struct node * selectSort(struct node *head)
/*ѡ������ ���� 
*/
{
    struct node *head1,*max,*premax,*t,*pret;
    //head1���������ͷָ�룻max��ԭ���������Ľ�㣻premax��������ǰ����㣻t�����ڱ���ԭ����Ѱ�������;pret:t��ǰ�����
    head1=NULL;
    while(head)//һ������ԭ�����е�ǰ����� 
    {
        max=head;
        premax=NULL;
        pret=head;
        t=head->next;
        //1��Ѱ������� 
        while(t){
            if(t->data>max->data){
                max=t;
                premax=pret;
            }
            pret=t;
            t=t->next;    
        }
        //2�����������뿪ԭ����
        if(max==head)//����ҵ��Ľ���ǵ�һ�����
            head=head->next;//��ͷָ�������һλ����
        else
            premax->next=max->next;
        //3���Ѵ˽��ͷ�巨����������
        max->next=head1;
        head1=max;
    }
    return head1;
}
