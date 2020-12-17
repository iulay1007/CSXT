typedef struct LNode {
    int data;
    LNode* next;
    LNode* prv;

} * DLinkList;
int ListToCir(DLinkList &L){
	DLinkList p,q;
	if(L==L->next)
	return -1;
	q=L;
	p=L->next; 
	
	while(p!=L)
	{
	p->prv=q;
	q=p;
	p=p->next;
	}
	if(p==L)
	p->prv=q;
	return 1;
}
