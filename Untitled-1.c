#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct goods
{
   int num;
   char name [20];
   int amount;
   float price;
   struct goods *next;
   
};
typedef struct goods NODE;
void menu();
void addGoodsMsg(NODE *head,NODE *tail);
void addGoodsAmount(NODE *head,NODE *tail);
void showGoodsMsg(NODE *head);
   
    NODE *head, *tail;

int main(){

   
    head=(NODE*)malloc(sizeof(NODE));
    if(head==NULL)
    return -1;
    head->next = NULL; //ͷ�ڵ��ָ������NULL 
    tail = head;

    while (1)
    {
        menu();
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    //������Ʒ��Ϣ
        addGoodsMsg(head,tail);
        break;
    //������Ʒ����
    case 2:
        addGoodsAmount(head,tail);
        break;
    //չʾ��Ʒ��Ϣ
    case 3:
        showGoodsMsg(head);
        break;
    default:
        break;
}

}
return 0;
}

void menu(){

    printf("�˵�\n");
    printf("1:������Ʒ��Ϣ\n");
    printf("2:������Ʒ����\n");
    printf("3:չʾ��Ʒ��Ϣ\n");
    printf("����������Ҫ���еĲ���\n");
    

}




//�����Ʒ
//˼����û��������е�
void addGoodsMsg(NODE *head,NODE *tail){

    NODE *pnew;
    pnew = (NODE *)malloc (sizeof(NODE));
    pnew->next=NULL;
   
    
    printf("��������Ʒ���� ���� �۸�");

    scanf("%s%d%f",&pnew->name,&pnew->amount,&pnew->price);
    printf("%s %d %.2f",pnew->name,pnew->amount,pnew->price);
    tail->next=pnew;
    tail=pnew;

    //�����ļ�����
    showGoodsMsg(head);

}

void addGoodsAmount(NODE *head,NODE *tail){
    printf("��������Ʒ���� ��Ҫ���ӵ�����");
    NODE *pnode;
     pnode = (NODE *)malloc (sizeof(NODE));
     pnode=head;
    char name[20];
    int pamount;
    scanf("%s%d",name,&pamount);
   // printf("%s  %d",name,pamount);
   while (pnode!=NULL)
   {
      if(strcmp(pnode->name,name)==0)
      {pnode->amount+=pamount;
      printf("%s%d",pnode->name,pnode->amount);
      break;
      }
      pnode=pnode->next;
      
   }
   if(pnode==NULL)
   printf("���ڿ������Ӹ���Ʒ");

   else
   {
       printf("error");
   }
   
    fflush(stdin);


}

void showGoodsMsg(NODE *head){
    NODE *pnode;
     pnode = (NODE *)malloc (sizeof(NODE));
     pnode=head;
    while (pnode!=NULL)
    {
        printf("%s",pnode->name);
        pnode=pnode->next;    }
    


}