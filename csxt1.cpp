#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct goods
{
   int num;
   char name [20];
   int amount;
   float price;
   struct goods *next;
   
};
struct goodsOnSale{
	char name [20];
	int amount;
   	float price;
   	struct goodsOnSale *next;
}; 

typedef struct goods NODE;
typedef struct goodsOnSale SNODE;
void menu();
NODE* creatNode(NODE *node);
void addGoodsMsg(NODE *head,NODE *tail);
void addGoodsAmount(NODE *head,NODE *tail);
void showGoodsMsg(NODE *head);
void saleGoods(NODE *node);
void readMsg(NODE *head);
void writeMsg(NODE *head);
void printTicket(SNODE *node);
struct tm * showTime();
    NODE *head, *tail;
   NODE *pnew,*rnode;
  
 
 
int main(){

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
    if(choice==0)
    return 0;
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
    printf("\t\t\t\t\t输入0结束\n");
	 printf("\t\t\t\t\t-----------------------\n"); 
    printf("\t\t\t\t\t请输入想要进行的操作:\n");
    printf("\t\t\t\t\t");
   
    

}
  struct tm * showTime(){
	 time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    printf ( "\t\t\t\t\t%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
  return lt;
} 
void readMsg(NODE *head)
{
	FILE *fpRead=fopen("data.txt","r");  
	fopen("data.txt","r");  
	  /*if(fpRead==NULL)  
    { 
        return 0;  
    } */
	rnode= creatNode(rnode);
	while(fscanf(fpRead,"%s %d %f",rnode->name,&rnode->amount,&rnode->price)!=EOF)
	{
	 

   rnode->next=head->next;
	head->next=rnode; 
	rnode= creatNode(rnode);  
	}
 	fclose(fpRead);
}



void writeMsg(NODE *head){

 FILE *wfpWrite=fopen("data.txt","wt");
fopen("data.txt","wt");
	rewind(wfpWrite);
	NODE* ntemp=creatNode(ntemp);
	ntemp=head->next;
	while(ntemp!=NULL){

	fprintf(wfpWrite,"%s %d %.2f\n",ntemp->name,ntemp->amount,ntemp->price);
	ntemp=ntemp->next;
	}
	fclose(wfpWrite);
	
}

NODE* creatNode(NODE *node){
	node=(NODE *)malloc (sizeof(NODE));
	node->next=NULL;
	return node;
}


void addGoodsMsg(NODE *head,NODE *tail){
	


   	pnew = creatNode(pnew);
    printf("\t\t\t\t\t请输入商品名字 数量 价格\n");
	printf("\t\t\t\t\t");
   	scanf("%s%d%f",pnew->name,&pnew->amount,&pnew->price);
 	 system("cls");
   	 printf("\n\n");
    printf("\t\t\t\t\t添加%s成功",pnew->name);
 
   //可行！！ 
    pnew->next=head->next;
	head->next=pnew; 
	
	//
	writeMsg(head);
  
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
	//	fprintf(fpWrite,"%s %d %.2f\n",pnode->name,pnode->amount,pnode->price);

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
	writeMsg(head);

}

void showGoodsMsg(NODE *head){
   NODE *ppnode;
       
    ppnode=head->next;
    printf("\t\t\t\t\t商品名\t\t商品数量\t商品价格\n");
    while (ppnode!=NULL)
    {
    
    printf("\t\t\t\t\t%s\t\t%d\t\t%.2f\n",ppnode->name,ppnode->amount,ppnode->price);
       if(ppnode->next==NULL)
       		break;
        ppnode=ppnode->next; 
      }
        
}

void saleGoods(NODE *head){
	NODE *pnode;
    pnode=head;
    SNODE *printlist;
    SNODE *listhead;
    printlist=(SNODE *)malloc (sizeof(SNODE));
	printlist->next=NULL;
	listhead=printlist;
    float price;
    char name[20];
    int pamount;
	printf("\t\t\t\t\t");
while(1){
	pnode=head;
	printf("\n\t\t\t\t\t");
	printf("请输入商品的名字和需要的数量\n");
	printf("\t\t\t\t\t-----------------------\n"); 
	printf("\t\t\t\t\t输入break结束购买\n");
	printf("\t\t\t\t\t-----------------------\n"); 
	printf("\t\t\t\t\t");
    scanf("%s",name);
    if(strcmp("break",name)==0)
    {
   	system("cls");
	break;
	}
   scanf("%d",&pamount);
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
	
	
		SNODE *temp;
		temp=(SNODE *)malloc (sizeof(SNODE));
		
		strcpy(temp->name,name);
		temp->amount=pamount;
		temp->price=price;
		temp->next=printlist->next;
		printlist->next=temp; 
		break; 
		} 
		pnode=pnode->next;
      
      }
      
      
   }

 printTicket(printlist);
  	writeMsg(head);
	
}

void printTicket(SNODE *node){
	 FILE *tfpWrite=fopen("ticket.txt","wt");
	SNODE *tnode;
	tnode=node->next;
	float total;
	  struct tm *lt;
	printf("\n\n\t\t\t\t\t-------------------------------------\n\n"); 
	fprintf(tfpWrite,"\n\n\t\t-------------------------------------\n\n");
	lt=showTime();
	fprintf (tfpWrite,"\t\t%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	printf("\n\t\t\t\t\t-------------------------------------\n");
	fprintf(tfpWrite,"\n\n\t\t-------------------------------------\n\n"); 
	printf("\t\t\t\t\t商品名\t\t商品数量\t商品价格\n\n");
	fprintf(tfpWrite,"\t\t商品名\t商品数量\t商品价格\n\n");
	while(tnode!=NULL){
	printf("\t\t\t\t\t%s\t\t%d\t\t%.2f\n",tnode->name,tnode->amount,tnode->price);
	fprintf(tfpWrite,"\t\t%s\t%d\t%.2f\n",tnode->name,tnode->amount,tnode->price);
	total+=tnode->price;
	   if(tnode->next==NULL)
       		break;
        tnode=tnode->next;
	}
	printf("\n\t\t\t\t\t-------------------------------------\n\n");
	fprintf(tfpWrite,"\n\n\t\t-------------------------------------\n\n");
	printf("\t\t\t\t\t应收:\t%.2f",total); 
	fprintf(tfpWrite,"\t\t应收:\t%.2f",total);
	fclose(tfpWrite);
}
