#include <stdio.h>
#include <malloc.h>
typedef int Elemtype;
 struct Node{
	Elemtype data;
	Node * next;
};
typedef struct Node Node;
typedef Node * pNode;
typedef struct{
	int size;
	pNode rear;
}Queue;

int InitQueue(Queue &queue) {
	queue.rear=NULL;
	queue.size=0;
	return 1;
}


int EnterQueue(Queue & queue,Elemtype e){
	queue.size++;
	pNode node=new Node;
	node->data=e;
	if(!queue.rear){
		queue.rear=node;
		node->next=node;
	}
	else{
	
	 node->next=queue.rear->next;
	 queue.rear->next=node;
	 queue.rear=node; 
	 
	 }
	 
	 return 1;
	
}

int DeleteInQueue(Queue & queue,Elemtype e){
	pNode node; 
	if(!queue.rear)
	return 0;
	 if(queue.size==1)
	{
		node=queue.rear;
		e=node->data;
		queue.rear=NULL;
		delete node;
	} 
	else {
		node=queue.rear->next;
		e=node->data;
		queue.rear->next=node->next;
		delete node;
	}
	queue.size--;
	return 1;
	
}

