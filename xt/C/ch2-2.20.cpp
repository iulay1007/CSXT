/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/submissions/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      
       if(head==NULL||head->next==NULL)
       return head;
        ListNode* tail;
        ListNode* L;
        L=head;
	
	tail=head->next;

	int i=0;
	while(tail!=NULL)
	{
		while(tail!=NULL&&tail->val==head->val)
		{
			tail=tail->next;
	
		i++;
		
		} 
		
		head->next=tail;
	
		if(head->next!=NULL)
		head=head->next;
    if(tail==NULL||tail->next==NULL)
    break;
    else
		tail=tail->next; 
	}

	head=head->next;

      return L;  
    }
    
};

//ÁíÒ»ÖÖĞ´·¨ 

struct ListNode* deleteDuplicates(struct ListNode* head){

if(head==NULL||head->next==NULL)
return head;

//struct ListNode* dum=(struct ListNode*)malloc(sizeof(struct ListNode));
//struct ListNode* nnext=(struct ListNode*)malloc(sizeof(struct ListNode));


struct ListNode* node=head;
while(node!=NULL&&node->next!=NULL)
{
if(node->val==node->next->val){
   node->next=node->next->next;

}
else {
  node=node->next;
}
}
    return head;
}
 
