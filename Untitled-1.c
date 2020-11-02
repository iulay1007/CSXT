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
NODE* creatNode(NODE *node);
void addGoodsMsg(NODE *head,NODE *tail);
void addGoodsAmount(NODE *head,NODE *tail);
void showGoodsMsg(NODE *head);
void saleGoods(NODE *node);
void readMsg(NODE *head);
void writeMsg(NODE *head);

    NODE *head, *tail;
   NODE *pnew,*rnode;
   FILE *fpRead=fopen("data.txt","r");  

  FILE *fpWrite=fopen("data.txt","at+");
int main(){


    if(fpWrite==NULL)  
    {  
        return 0;  
    } 
     
    if(fpRead==NULL)  
    { 
        return 0;  
    } 
    
     
   
	 
    //
     //   printf("\t\t\t\t\t%s\t\t%d\t\t%.2f\n",pnew->name,pnew->amount,pnew->price);

   // printf("%s%d%f",pnew->name,&pnew->amount,&pnew->price);
    head=(NODE*)malloc(sizeof(NODE));
    
  
    if(head==NULL)
    return -1;
  
    head->next=tail;

  readMsg(head);
    while (1)
    {
    	printf("\t\t\t\t\t");
        menu();
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    //增加商品 
        addGoodsMsg(head,tail);
        break;
    //增加数量 
    case 2:
        addGoodsAmount(head,tail);
        break;
    //展示商品信息 
    case 3:
        showGoodsMsg(head);
        break;
    //销售商品 
    case 4:
    	saleGoods(head);
    	break;
    default: 
	printf("nothing!!"); 
	break;
    
}

}

//fclose(fpWrite); 
return 0;
}

void menu(){

	
    printf("\n\n\t\t\t\t\t\t菜单\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t1:增加商品\n");
    printf("\t\t\t\t\t2:增加商品数量\n");
    printf("\t\t\t\t\t3:展示商品信息\n");
     printf("\t\t\t\t\t4:销售商品\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t请输入想要进行的操作:\n");
    printf("\t\t\t\t\t");
   
    

}
void readMsg(NODE *head)
{
		rnode= creatNode(rnode);
	while(fscanf(fpRead,"%s %d %f",rnode->name,&rnode->amount,&rnode->price)!=EOF)
{
	 

   rnode->next=head->next;
	head->next=rnode; 
	rnode= creatNode(rnode);  
	}
 	fclose(fpRead);
}
NODE* creatNode(NODE *node){
	node=(NODE *)malloc (sizeof(NODE));
	node->next=NULL;
	return node;
}


void addGoodsMsg(NODE *head,NODE *tail){
	
		fopen("data.txt","at+");
//	fscanf(fpWrite,"%s",pnew->name);
	//printf("%s",pnew->name); 

   	pnew = creatNode(pnew);
    printf("\t\t\t\t\t请输入商品名字 数量 价格\n");
	printf("\t\t\t\t\t");
   	scanf("%s%d%f",pnew->name,&pnew->amount,&pnew->price);
   	fprintf(fpWrite,"%s %d %.2f\n",pnew->name,pnew->amount,pnew->price);
   	fclose(fpWrite);
   	
   
   	// fprintf(fpWrite,"%s%d%f",pnew->name,&pnew->amount,&pnew->price);
   	
   	 system("cls");
   	 printf("\n\n");
    printf("\t\t\t\t\t添加%s成功",pnew->name);
 
   //可行！！ 
    pnew->next=head->next;
	head->next=pnew; 
  
}

void addGoodsAmount(NODE *head,NODE *tail){
	
    printf("\t\t\t\t\t请输入想增加的商品名字 数量\n");
    NODE *pnode;
   
     pnode=head;
    char name[20];
    int pamount;
    	printf("\t\t\t\t\t");
    scanf("%s%d",name,&pamount);
  
   while (pnode!=NULL)
   {
      if(strcmp(pnode->name,name)==0)
      {
	  pnode->amount+=pamount;
	     	 system("cls");
	  printf("\t\t\t\t\t增加数量成功\n");
      printf("\t\t\t\t\t%s的数量为%d",pnode->name,pnode->amount);
      break;
      }
      pnode=pnode->next;
      
   }
   if(pnode==NULL)
   {
   	system("cls");
   	printf("\n\n");
   printf("\t\t\t\t\t请先添加商品\n");} 

    fflush(stdin);


}

void showGoodsMsg(NODE *head){
   NODE *pnode;
       
    pnode=head->next;
    while (pnode!=NULL)
    {
    printf("\t\t\t\t\t商品名\t\t商品数量\t商品价格\n");
    printf("\t\t\t\t\t%s\t\t%d\t\t%.2f\n",pnode->name,pnode->amount,pnode->price);
       if(pnode->next==NULL)
       		break;
        pnode=pnode->next; 
      }
        
}

void saleGoods(NODE *head){
	 NODE *pnode;
     pnode=head;
     float price;
       char name[20];
    int pamount;
	printf("\t\t\t\t\t");
	printf("请输入商品的名字和需要的数量\n");
	printf("\t\t\t\t\t");
    scanf("%s%d",name,&pamount);
  
   while (pnode!=NULL)
   {
      if(strcmp(pnode->name,name)==0)
      {
      	if(pnode->amount<pamount)
      	{
		  printf("\t\t\t\t\t数量不足\n"); 
		  break;
		}
		price=pnode->price*pamount;
	  pnode->amount-=pamount;
		printf("\t\t\t\t\t价格为%.2f\n",price);
      printf("\t\t\t\t\t%s的数量为%d",pnode->name,pnode->amount);
      break;
      }
      pnode=pnode->next;
      
   }
	
}