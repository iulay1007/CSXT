#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
struct goods
{
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
	int identity;//身份识别码 
	struct User *next;
}; 

typedef struct goods NODE;
typedef struct goodsOnSale SNODE;
struct tm * showTime();
//菜单 
void menuOne();
void menuTwo();
void registerOrLoginMenu();
//注册 
void register1(); 
//登录 
int login();
//建立节点 
NODE* creatNode(NODE *node);
User* creatUser(User *node);
//检查User的名字与密码是否正确 
int checkinUser(char *username,char *password);
//登录状态检测 
int login_callback(int code);
//查询是否存在user ，根据返回值判断结果 
int searchUser(char *username);
//寻找User并返回User 
User* findUser(User *head,char *username); 
//增加User信息 
void addUserMsg(User *node);
//读入User信息 
void readUserMsg(User *head); 
//写入User信息 
void writeUserMsg(User *head);
//增加商品信息 
void addGoodsMsg(NODE *head);
//增加商品数量 
void addGoodsAmount(NODE *head);
//展示商品信息 
void showGoodsMsg(NODE *head);
//销售商品 
void saleGoods(NODE *node);
//读入商品信息 
void readMsg(NODE *head);
//删除商品 
void deleteGoods(NODE *head); 
//写入商品信息 
void writeMsg(NODE *head);
//打印小票 
void printTicket(SNODE *node);


	NODE *head, *tail;
   NODE *pnew,*rnode;
   User *uhead,*unode;
   //登录的User 
   User *user;
 
int main(){
	int temp;
	int ch;
    head=(NODE*)malloc(sizeof(NODE));
  	uhead=creatUser(uhead);
    if(head==NULL)
    return -1;
    head->next=tail;	
   readMsg(head);
   readUserMsg(uhead);
   registerOrLoginMenu();
   scanf("%d",&temp);
   system("cls");
   //注册/登录界面 
   while(1){
   if(temp==1)
    {
    	//根据登录返回结果决定下一步操作 
    	int result=login();
	if(result==0)
	{
	printf("\t\t\t\t\t-----------------------\n");
   printf("\n\t\t\t\t\t   输入1：重新登录\n\t\t\t\t\t   输入2：注册\n\n");
    printf("\t\t\t\t\t-----------------------\n");
   printf("\t\t\t\t\t");
   scanf("%d",&ch);
   if(ch==2)
   {
   register1();
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
	// 1:销售员    2:库存管理员
	//根据User的身份标识决定展示什么菜单 
	if(user->identity==1)
	{	
	while(1){
		printf("\t\t\t\t\t");
        menuOne();
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 0:
    	system("cls");
		return 0; 
    case 1:
    //销售商品 
       saleGoods(head);
        break;
    //增加数量 
    case 2:
    //展示商品信息 
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
        menuTwo();
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 0:
    	system("cls");
		return 0; 
    case 1:
    //增加商品 
        addGoodsMsg(head);
        break;
    //增加数量 
    case 2:
        addGoodsAmount(head);
        break;
    //展示商品信息 
    case 3:
        showGoodsMsg(head);
        break;
    //销售商品 
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

//注册User 
	void register1(){
		system("cls");
	User *user;
	user=creatUser(user);
	char username[20];
    char password[20];
	int identity; 
	int flag=0;
	  printf("\n\n\t\t\t\t\t\t注册\n");
	    printf("\t\t\t\t\t-----------------------\n");
	    
	    printf("\t\t\t\t\t    请输入用户名:\n");
	    
		while(1)	{
		printf("\t\t\t\t\t");
		  scanf("%s",user->name);
		  //查找User列表看是否已存在该用户 
	   int callback= searchUser(user->name);
	   if (callback==1)
	   {
	   printf("\n\t\t\t\t\t用户名已存在，请重新输入用户名:\n");
	   }
	   else 
	break;
	   }
	    printf("\n\t\t\t\t\t    请输入密码:\n");
		printf("\t\t\t\t\t");
		scanf("%s",user->password);
		printf("\t\t\t\t\t    请选择身份\n");
		printf("\t\t\t\t\t    1:销售员\n\t\t\t\t\t    2:库存管理员\n\t\t\t\t\t");
		scanf("%d",&user->identity);
		//写入User信息 
		addUserMsg(user);
		
} 

int login(){

	char username[20];
    char password[20];
	int result; 
	  printf("\n\n\t\t\t\t\t\t登录\n");
	    printf("\t\t\t\t\t-----------------------\n");
	  printf("\t\t\t\t\t    请输入用户名:\n");
		printf("\t\t\t\t\t");
	   scanf("%s",username);
	  
	     printf("\t\t\t\t\t    请输入密码:\n");
		printf("\t\t\t\t\t");
		 scanf("%s",password);
		result=	checkinUser(username,password); 
		//根据result决定显示的提示信息 
		login_callback(result);
		if(result==1)
		user=findUser(uhead,username); 
		  //检测用户名是否存在 
		 //检测密码是否正确 
	
		 return result;
	
}

int login_callback(int code){
		if(code==0)
		printf("\n\t\t\t\t\t    用户不存在\n");
		else if(code==1){
		
			printf("\n\t\t\t\t\t    登录成功!\n ");
			Sleep(1000);
			}
		else if(code==2)
			printf("\n\t\t\t\t\t    密码错误 \n");
		return code;
}

//读入User的信息 
void readUserMsg(User *head){
	 
		FILE *ufRead=fopen("User.txt","r");  
	fopen("User.txt","r");  

	unode= creatUser(unode);
	while(fscanf(ufRead,"%s %s %d",unode->name,unode->password,&unode->identity)!=EOF)
	{
	 

   unode->next=uhead->next;
	uhead->next=unode; 
	unode= creatUser(unode);  
	}
 	fclose(ufRead);
}
//写入User的信息 
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
//添加User 
void addUserMsg(User *node){
	
 
    node->next=uhead->next;
	uhead->next=node; 	
	writeUserMsg(uhead);
	
	
}

//查询User是否存在 
int searchUser(char *username){
	User *snode;
   
     snode=uhead;
    char name[20];
   
    	printf("\t\t\t\t\t");
    
  
   while (snode!=NULL)
   {
      if(strcmp(snode->name,username)==0)
      {
      	return 1;//用户存在 
	  }
	  snode=snode->next; 
	 } 
	 return 0;//不存在用户名，可创建 
}

//寻找User并返回 
User* findUser(User *head,char *username ){
		User *tnode;
   		tnode=uhead;
    	
    	printf("\t\t\t\t\t");
    
  
   while (tnode!=NULL)
   {
      if(strcmp(tnode->name,username)==0)
      {
      	return tnode;//用户存在 
	  }
	  tnode=tnode->next; 
	 } 
	 return tnode;//不存在用户名，可创建 
	}
//检查User的账号密码 
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
	     return 1;//登录成功 
      else return 2;//密码错误 
      }
      pnode=pnode->next;
      
   }
   if(pnode==NULL)
   {
   	system("cls");
   	printf("\n\n");
	
    fflush(stdin);
    return 0;//用户不存在 
}
} 
//创建User节点 
User* creatUser(User *node){
		node=(User *)malloc (sizeof(User));
	node->next=NULL;
	return node;
}
//读取商品信息 
void readMsg(NODE *head)
{
	FILE *fpRead=fopen("data.txt","r");  
	fopen("data.txt","r");  
	  
	rnode= creatNode(rnode);
	while(fscanf(fpRead,"%s %d %f %d %f",rnode->name,&rnode->amount,&rnode->price,&rnode->sale_amount,&rnode->sale_money)!=EOF)
	{
	 
   rnode->next=head->next;
	head->next=rnode; 
	rnode= creatNode(rnode);  
	}
 	fclose(fpRead);
}


//写入商品信息 
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

//创建商品节点 
NODE* creatNode(NODE *node){
	node=(NODE *)malloc (sizeof(NODE));
	node->next=NULL;
	return node;
}

//添加商品信息 
void addGoodsMsg(NODE *head){
	

while(1){

   	pnew = creatNode(pnew);
    printf("\t\t\t\t\t请输入商品名字 数量 价格\n");
   	printf("\t\t\t\t\t-----------------------\n"); 
	printf("\t\t\t\t\t输入break结束添加\n");
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
    printf("\t\t\t\t\t添加%s成功\n",pnew->name);
  
    pnew->next=head->next;
	head->next=pnew; 
	
}

	writeMsg(head);
  
}
//增加商品数量 
void addGoodsAmount(NODE *head){


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
	writeMsg(head);

}

//展示商品信息 
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

//销售商品 
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
	
	
		pnode->sale_amount+=pamount;
		pnode->sale_money=pnode->sale_money+price; 
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
	printf("\t\t\t\t\t\t输入Y打印小票 \n");
	printf("\n\n\t\t\t\t\t-------------------------------------\n\n"); 
	printf("\t\t\t\t\t\t");
  	scanf("%c",&ch);
	  if(ch == 'Y') {
	  system("cls");
	 printTicket(printlist);
	 }
  	writeMsg(head);
  
}

//打印小票 
void printTicket(SNODE *node){
	FILE *tfpWrite=fopen("ticket.txt","wt");
	SNODE *tnode;
	tnode=node->next;
	float total;
	  struct tm *lt;
	printf("\n\n\t\t\t\t\t-------------------------------------\n\n"); 
	fprintf(tfpWrite,"\n\n\t\t-------------------------------------\n\n");
	lt=showTime();
	fprintf (tfpWrite,"\t\t%d/%d/%d %d:%d:%d\n",lt->tm_year+1900,
	 lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	fprintf(tfpWrite,"\t\t\t\t\t销售员：%s\n",user->name);
	printf("\t\t\t\t\t销售员：%s\n",user->name);
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

//删除商品 
void deleteGoods(NODE *head){
	
	 printf("\t\t\t\t\t请输入想删除的商品名字\n");
    NODE *pnode;
   	NODE *prv;
   
     pnode=head;
    char name[20];
  printf("\t\t\t\t\t");
     scanf("%s",name);
  
   while (pnode!=NULL)
   {
      if(strcmp(pnode->name,name)==0)
      {
	 
	     	 system("cls");
	  
      printf("\t\t\t\t\t删除%s成功",pnode->name);
     
      prv->next=pnode->next;
    
      break;
      }
        prv=pnode;
      pnode=pnode->next;
    
      
   }
   if(pnode==NULL)
   {
   	printf("\n\n");
   printf("\t\t\t\t\t不存在该商品\n");} 

	writeMsg(head);

}

void menuOne(){

	printf("\n\n\t\t\t\t\t\t菜单\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t1:销售商品\n");
    printf("\t\t\t\t\t2:展示商品信息\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t输入0结束\n");
	 printf("\t\t\t\t\t-----------------------\n"); 
    printf("\t\t\t\t\t请输入想要进行的操作:\n");
    printf("\t\t\t\t\t");
   

}
void menuTwo(){

	
    printf("\n\n\t\t\t\t\t\t菜单\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t1:增加商品\n");
    printf("\t\t\t\t\t2:增加商品数量\n");
    printf("\t\t\t\t\t3:展示商品信息\n");
     printf("\t\t\t\t\t4:删除商品\n");
    printf("\t\t\t\t\t-----------------------\n");
    printf("\t\t\t\t\t输入0结束\n");
	 printf("\t\t\t\t\t-----------------------\n"); 
    printf("\t\t\t\t\t请输入想要进行的操作:\n");
    printf("\t\t\t\t\t");
   
    

}
void registerOrLoginMenu(){
 printf("\t\t\t\t\t-----------------------\n");
   printf("\n\t\t\t\t\t   输入1：登录\n\t\t\t\t\t   输入2：注册\n\n");
    printf("\t\t\t\t\t-----------------------\n");
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

