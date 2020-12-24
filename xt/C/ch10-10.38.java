/*归并排序的含义   将两个或者两个以上的有序表组合成一个新的有序表

该题使用的是二路归并，即   两个有序表组合成一个新的有序表

public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}*/

public ListNode sortListII(ListNode head){
            if(head==null || head.next==null)
                return head;
            ListNode fast = head;
            ListNode slow = head;
            while (fast.next!=null &&fast.next.next!=null){
                fast = fast.next.next;
                slow = slow.next;
            }
 
            ListNode mid = slow.next;
            slow.next = null;
            ListNode left = sortListII(head);
            ListNode right = sortListII(mid);
            return  concat(left,right);
        }//二路归并排序    快慢指针
public ListNode concat(ListNode root1,ListNode root2){
            ListNode root = null;
            //寻找二路归并的头节点
            if(root1.val<root2.val){
                root = root1;
                root1 = root1.next;
            }else{
                root = root2;
                root2 = root2.next;
            }
            //工作节点
            ListNode p = root;
            while (root1!=null && root2!=null){
                if(root1.val<root2.val){
                    p.next = root1;
                    root1 = root1.next;
                }else{
                    p.next = root2;
                    root2 = root2.next;
                }
                p = p.next;
            }
            //连接上 最后剩下的有序链表
            p.next = root1==null ? root2 : root1;
            //返回头节点
            return root;
        }//二路合一