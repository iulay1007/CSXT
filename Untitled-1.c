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
    head->next = NULL; //头节点的指针域置NULL 
    tail = head;

    while (1)
    {
        menu();
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    //增加商品信息
        addGoodsMsg(head,tail);
        break;
    //增加商品数量
    case 2:
        addGoodsAmount(head,tail);
        break;
    //展示商品信息
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

    printf("菜单\n");
    printf("1:增加商品信息\n");
    printf("2:增加商品数量\n");
    printf("3:展示商品信息\n");
    printf("请输入你想要进行的操作\n");
    

}




//添加商品
//思考有没有添加已有的
void addGoodsMsg(NODE *head,NODE *tail){

    NODE *pnew;
    pnew = (NODE *)malloc (sizeof(NODE));
    pnew->next=NULL;
   
    
    printf("请输入商品名字 数量 价格");

    scanf("%s%d%f",&pnew->name,&pnew->amount,&pnew->price);
    printf("%s %d %.2f",pnew->name,pnew->amount,pnew->price);
    tail->next=pnew;
    tail=pnew;

    //读入文件！！
    showGoodsMsg(head);

}

void addGoodsAmount(NODE *head,NODE *tail){
    printf("请输入商品名字 想要增加的数量");
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
   printf("请在库存里添加该商品");

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