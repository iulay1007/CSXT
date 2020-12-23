/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

//我刚开始到底错哪了！！！！！！！！！！！！！累了
public class Solution147 {
    public ListNode insertionSortList(ListNode head) {
        if(head==null||head.next==null)
            return head;
        ListNode prv=new ListNode(0);
        prv.next=head;
        ListNode pre = head;
        ListNode nnode=head.next;


        while(nnode!=null)
        {
            if(pre.val<=nnode.val)
            {
                pre=nnode;
                nnode=nnode.next;
            }

            else  {
                ListNode p = prv;
                while(nnode.val>p.next.val)
                {
                    p=p.next;
                }

                pre.next = nnode.next;
                nnode.next=p.next;
                p.next=nnode;
                nnode=pre.next;
            }

        }


        return prv.next;
    }
}