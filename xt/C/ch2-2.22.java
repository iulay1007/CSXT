import java.util.Stack;

/**
 *
 * 206. 反转链表
 * 反转一个单链表。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


///要小心的是 n1 的下一个必须指向 null 。如果你忽略了这一点，你的链表中可能会产生循环。如果使用大小为 2 的链表测试代码，则可能会捕获此错误。

class Solution206 {

        public ListNode reverseList(ListNode head) {
            if(head==null) return head;
            ListNode prv=new ListNode(0);

            Stack<Integer> stack=new Stack<>();
            while (head!=null)
            {
                stack.push(head.val);
                head=head.next;
            }
            head=prv;
            while (!stack.isEmpty()){
                ListNode temp=new ListNode(stack.pop());
                prv.next=temp;
                prv=prv.next;

            }
            return head.next;
        }
    }
/*/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
  ListNode temp=new ListNode(0);
  ListNode result=new ListNode(0);
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null)     return head;
        ListNode nnode=head.next;
        head.next=null;
    helper(head,nnode);
     return   result;

    }

    private ListNode helper(ListNode pnode,ListNode node) {
        if(node==null)
        result=pnode;
        if (pnode==null||node==null) return node;
           temp=node.next;
        node.next=pnode;
        helper(node,temp);
        return node;
    }

}
}*/

/*
//很妙的递归
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode p = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }
}
*/

/*迭代
反向即可！!!
class Solution {
	public ListNode reverseList(ListNode head) {
		//申请节点，pre和 cur，pre指向null
		ListNode pre = null;
		ListNode cur = head;
		ListNode tmp = null;
		while(cur!=null) {
			//记录当前节点的下一个节点
			tmp = cur.next;
			//然后将当前节点指向pre
			cur.next = pre;
			//pre和cur节点都前进一位
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
}
*/