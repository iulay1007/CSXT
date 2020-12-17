typedef struct LNode {
    int data;
    LNode* next;

}LNode, * LinkList;
int deletePre(LinkList &L)
{
	LinkList p,q;
	if(L==L->next)
	return 0;
	q=L;
	p=L->next;
	while(p->next!=L)
	{
		q=p;
		p=p->next;
		 
	}
	q->next=p->next;
	free(p);
	return 1; 
}
