#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
struct goods
{
   int num;
   char name [20];
   int amount;
   float price;
   int sale_amount;
   float sale_money;
   struct goods *next;
   
};

struct goodsOnSale{
	char name [20];
	int amount;
   	float price;
   	struct goodsOnSale *next;
}; 

struct User{
	char name[20];
	char password[20];
	int identity;//���ʶ���� 
	struct User *next;
}; 

typedef struct goods NODE;
typedef struct goodsOnSale SNODE;
struct tm * showTime();
void menu1();
void menu2();
void register1(); 
int login();
NODE* creatNode(NODE *node);
User* creatUser(User *node);
int checkinUser(char *username,char *password);
int login_callback(int code);
int searchUser(char *username);
User* findUser(User *head,char *username); 
void addUserMsg(User *node);
void readUserMsg(User *head); 
void writeUserMsg(User *head);
void addGoodsMsg(NODE *head);
void addGoodsAmount(NODE *head,NODE *tail);
void showGoodsMsg(NODE *head);
void saleGoods(NODE *node);
void readMsg(NODE *head);
void deleteGoods(NODE *head); 
void writeMsg(NODE *head);
void printTicket(SNODE *node);


	NODE *head, *tail;
   NODE *pnew,*rnode;
   User *uhead,*unode;
   User *user;
 
int main(){
	int temp;
	int ch;
    head=(NODE*)malloc(sizeof(NODE));
  uhead=creatUser(uhead);
    if(head==NULL)
    return -1;
   //ɾ�� 
    head->next=tail;	
   readMsg(head);
   readUserMsg(uhead);
     printf("\t\t\t\t\t-----------------------\n");
   printf("\n\t\t\t\t\t   ����1����¼\n\t\t\t\t\t   ����2��ע��\n\n");
    printf("\t\t\t\t\t-----------------------\n");
   printf("\t\t\t\t\t");
   scanf("%d",&temp);
   system("cls");
   while(1){
   
  
   if(temp==1)
    {
    	int result=login();
    
	if(result==0)
	{
	printf("\t\t\t\t\t-----------------------\n");
   printf("\n\t\t\t\t\t   ����1�����µ�¼\n\t\t\t\t\t   ����2��ע��\n\n");
    printf("\t\t\t\t\t-----------------------\n");
   printf("\t\t\t\t\t");
   scanf("%d",&ch);
   //  system("cls");
   if(ch==2)
   {
   register1();
   //
   }
   if(ch==1)
   {
   temp=1;
   continue;
   }
   
   
   }else if(result==1)
   break;
  

	}

	else if(temp==2) 
   {
   register1();
   temp=1;
    continue;

   }
}
	system("cls");
	// 1:����Ա\n\t\t\t\t\t    2:������Ա
	if(user->identity==1)
	{	
	while(1){
		printf("\t\t\t\t\t");
        menu1();
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 0:
    	system("cls");
		return 0; 
    case 1:
    //������Ʒ 
       saleGoods(head);
        break;
    //�������� 
    case 2:
    //չʾ��Ʒ��Ϣ 
        showGoodsMsg(head);
        break; 
    default: 
    printf("\t\t\t\t\t");
	printf("nothing!!"); 
	break;
	
}
	}}
else if(user->identity==2)
{
	while(1){
		 
    	printf("\t\t\t\t\t");
        menu2();
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 0:
    	system("cls");
		return 0; 
    case 1:
    //������Ʒ 
        addGoodsMsg(head);
        break;
    //�������� 
    case 2:
        addGoodsAmount(head,tail);
        break;
    //չʾ��Ʒ��Ϣ 
    case 3:
        showGoodsMsg(head);
        break;
    //������Ʒ 
    case 4:
    	deleteGoods(head);
    	break; 
    default: 
    printf("\t\t\t\t\t");
	printf("nothing!!"); 
	break;
	}
}

   

}

return 0;
}
	void register1(){
		system("cls");
	User *user;
	user=creatUser(user);
	char username[20];
    char password[20];
	int identity; 
	int flag=0;
	  printf("\n\n\t\t\t\t\t\tע��\n");
	    printf("\t\t\t\t\t-----------------------\n");
	    
	    printf("\t\t\t\t\t    �������û���:\n");
	    
			while(1)	{
		printf("\t\t\t\t\t");
		  scanf("%s",user->name);
	   int callback= searchUser(user->name);
	   if (callback==1)
	   {
	   printf("\n\t\t\t\t\t�û����Ѵ��ڣ������������û���:\n");
	   }
	   else 
	   
		break;
	   }

	    printf("\n\t\t\t\t\t    ����������:\n");
		printf("\t\t\t\t\t");
		scanf("%s",user->password);
		printf("\t\t\t\t\t    ��ѡ�����\n");
		printf("\t\t\t\t\t    1:����Ա\n\t\t\t\t\t    2:������Ա\n\t\t\t\t\t");
		scanf("%d",&user->identity);
		addUserMsg(user);
		
} 

int login(){

	//User *user;
	char username[20];
    char password[20];
	int result; 
	  printf("\n\n\t\t\t\t\t\t��¼\n");
	    printf("\t\t\t\t\t-----------------------\n");
	  printf("\t\t\t\t\t    �������û���:\n");
		printf("\t\t\t\t\t");
	   scanf("%s",username);
	  
	     printf("\t\t\t\t\t    ����������:\n");
		printf("\t\t\t\t\t");
		 scanf("%s",password);
		result=	checkinUser(username,password); 
		login_callback(result);
		//!!!!!
		if(result==1)
		user=findUser(uhead,username); 
		  //����û����Ƿ���� 
		 //��������Ƿ���ȷ 
		 //if()0,1,2
		 return result;
	
}

int login_callback(int code){
		if(code==0)
		printf("\n\t\t\t\t\t    �û�������\n");
		else if(code==1){
		
			printf("\n\t\t\t\t\t    ��¼�ɹ�!\n ");
			Sleep(1000);
			}
		else if(code==2)
			printf("\n\t\t\t\t\t    ������� \n");
		return code;
}
void readUserMsg(User *head){
		FILE *ufRead=fopen("User.txt","r");  
	fopen("User.txt","r");  
	  /*if(fpRead==NULL)  
    { 
        return 0;  
    } */
	unode= creatUser(unode);
	while(fscanf(ufRead,"%s %s %d",unode->name,unode->password,&unode->identity)!=EOF)
	{
	 

   unode->next=uhead->next;
	uhead->next=unode; 
	unode= creatUser(unode);  
	}
 	fclose(ufRead);
}

void writeUserMsg(User *head){
	FILE *ufpWrite=fopen("User.txt","wt");
	fopen("User.txt","wt");
	rewind(ufpWrite);
	User* utemp=creatUser(utemp);
	utemp=head->next;
	while(utemp!=NULL){

	fprintf(ufpWrite,"%s %s %d\n",utemp->name,utemp->password,utemp->identity);
	utemp=utemp->next;
	}
	fclose(ufpWrite);
	
} 

void addUserMsg(User *node){
	
	
   //���У��� 
    node->next=uhead->next;
	uhead->next=node; 
	
	writeUserMsg(uhead);
	
	
}

int searchUser(char *username){
	User *snode;
   
     snode=uhead;
    char name[20];
   
    	printf("\t\t\t\t\t");
    
  
   while (snode!=NULL)
   {
      if(strcmp(snode->name,username)==0)
      {
      	return 1;//�û����� 
	  }
	  snode=snode->next; 
	 } 
	 return 0;//�������û������ɴ��� 
}

User* findUser(User *head,char *username ){
		User *tnode;
   		tnode=uhead;
    	
    	printf("\t\t\t\t\t");
    
  
   while (tnode!=NULL)
   {
      if(strcmp(tnode->name,username)==0)
      {
      	return tnode;//�û����� 
	  }
	  tnode=tnode->next; 
	 } 
	 return tnode;//�������û������ɴ��� 
	}

int checkinUser(char *username,char *password){
	
	User *pnode;
   
     pnode=uhead;
    char name[20];
   
    	printf("\t\t\t\t\t");
    
     while (pnode!=NULL)
   {
      if(strcmp(pnode->name,username)==0)
      {
	 
		if(strcmp(pnode->password,password)==0)
	     return 1;//��¼�ɹ� 
      else return 2;//������� 
      }
      pnode=pnode->next;
      
   }
   if(pnode==NULL)
   {
   	system("cls");
   	printf("\n\n");
	
    fflush(stdin);
    return 0;//�û������� 
}
} 

User* creatUser(User *node){
		node=(User *)malloc (sizeof(User));
	node->next=NULL;
	return node;
}
void menu1(){

	printf("\n\n\t\t\t\t\t\t�˵�\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t1:������Ʒ\n");
    printf("\t\t\t\t\t2:չʾ��Ʒ��Ϣ\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t����0����\n");
	 printf("\t\t\t\t\t-----------------------\n"); 
    printf("\t\t\t\t\t��������Ҫ���еĲ���:\n");
    printf("\t\t\t\t\t");
   

}
void menu2(){

	
    printf("\n\n\t\t\t\t\t\t�˵�\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t1:������Ʒ\n");
    printf("\t\t\t\t\t2:������Ʒ����\n");
    printf("\t\t\t\t\t3:չʾ��Ʒ��Ϣ\n");
     printf("\t\t\t\t\t4:ɾ����Ʒ\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t����0����\n");
	 printf("\t\t\t\t\t-----------------------\n"); 
    printf("\t\t\t\t\t��������Ҫ���еĲ���:\n");
    printf("\t\t\t\t\t");
   
    

}
  struct tm * showTime(){
	 time_t t;
    struct tm * lt;
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    printf ( "\t\t\t\t\t%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//������
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
	while(fscanf(fpRead,"%s %d %f %d %f",rnode->name,&rnode->amount,&rnode->price,&rnode->sale_amount,&rnode->sale_money)!=EOF)
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

	fprintf(wfpWrite,"%s %d %.2f %d %.2f\n",ntemp->name,ntemp->amount,ntemp->price,ntemp->sale_amount,ntemp->sale_money);
	ntemp=ntemp->next;
	}
	fclose(wfpWrite);
	
}

NODE* creatNode(NODE *node){
	node=(NODE *)malloc (sizeof(NODE));
	node->next=NULL;
	return node;
}


void addGoodsMsg(NODE *head){
	

while(1){

   	pnew = creatNode(pnew);
    printf("\t\t\t\t\t��������Ʒ���� ���� �۸�\n");
   	printf("\t\t\t\t\t-----------------------\n"); 
	printf("\t\t\t\t\t����break�������\n");
	printf("\t\t\t\t\t-----------------------\n"); 
	printf("\t\t\t\t\t");
   	scanf("%s",pnew->name);
   	 if(strcmp("break",pnew->name)==0)
    {
   	system("cls");
	break;
	}
   	scanf("%d%f",&pnew->amount,&pnew->price);
   		pnew->sale_amount=0;
		pnew->sale_money=0;
 	 system("cls");
   	 printf("\n\n");
    printf("\t\t\t\t\t���%s�ɹ�\n",pnew->name);
 
   //���У��� 
    pnew->next=head->next;
	head->next=pnew; 
	
}
	//
	writeMsg(head);
  
}

void addGoodsAmount(NODE *head,NODE *tail){


    printf("\t\t\t\t\t�����������ӵ���Ʒ���� ����\n");
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
	  printf("\t\t\t\t\t���������ɹ�\n");
      printf("\t\t\t\t\t%s������Ϊ%d",pnode->name,pnode->amount);
      break;
      }
      pnode=pnode->next;
      
   }
   if(pnode==NULL)
   {
   	system("cls");
   	printf("\n\n");
   printf("\t\t\t\t\t���������Ʒ\n");} 

    fflush(stdin);
	writeMsg(head);

}

void showGoodsMsg(NODE *head){
   NODE *ppnode;
       
    ppnode=head->next;
    printf("\t\t\t\t\t��Ʒ��\t\t��Ʒ����\t��Ʒ�۸�\n");
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
    char ch;
	printf("\t\t\t\t\t");
while(1){
	pnode=head;
	printf("\n\t\t\t\t\t");
	printf("��������Ʒ�����ֺ���Ҫ������\n");
	printf("\t\t\t\t\t-----------------------\n"); 
	printf("\t\t\t\t\t����break��������\n");
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
 	printf("\t\t\t\t\t��������\n"); 
		  break;
		}	
		price=pnode->price*pamount;
	
	
		pnode->sale_amount+=pamount;
		pnode->sale_money=pnode->sale_money+price;
//		printf("\t\t%d\t%f\n",pnode->sale_amount,pnode->sale_money);
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
	fflush(stdin);
	printf("\t\t\t\t\t\t \n");
	printf("\t\t\t\t\t\t����Y��ӡСƱ \n");
	printf("\n\n\t\t\t\t\t-------------------------------------\n\n"); 
	printf("\t\t\t\t\t\t");
  	scanf("%c",&ch);
	  if(ch == 'Y') {
	  system("cls");
	 printTicket(printlist);
	 }
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
	fprintf(tfpWrite,"\t\t\t\t\t����Ա��%s\n",user->name);
	printf("\t\t\t\t\t����Ա��%s\n",user->name);
	printf("\n\t\t\t\t\t-------------------------------------\n");
	fprintf(tfpWrite,"\n\n\t\t-------------------------------------\n\n"); 
	printf("\t\t\t\t\t��Ʒ��\t\t��Ʒ����\t��Ʒ�۸�\n\n");
	fprintf(tfpWrite,"\t\t��Ʒ��\t��Ʒ����\t��Ʒ�۸�\n\n");
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
	printf("\t\t\t\t\tӦ��:\t%.2f",total); 
	fprintf(tfpWrite,"\t\tӦ��:\t%.2f",total);
	fclose(tfpWrite);
}


void deleteGoods(NODE *head){
	
	 printf("\t\t\t\t\t��������ɾ������Ʒ����\n");
    NODE *pnode;
   	NODE *prv;
   
     pnode=head;
    // prv->next=head;
    char name[20];
  printf("\t\t\t\t\t");
     scanf("%s",name);
  
   while (pnode!=NULL)
   {
      if(strcmp(pnode->name,name)==0)
      {
	 
	     	 system("cls");
	  
      printf("\t\t\t\t\tɾ��%s�ɹ�",pnode->name);
     
      prv->next=pnode->next;
    
      break;
      }
        prv=pnode;
      pnode=pnode->next;
    
      
   }
   if(pnode==NULL)
   {
  // 	system("cls");
   	printf("\n\n");
   printf("\t\t\t\t\t�����ڸ���Ʒ\n");} 

	writeMsg(head);

}


