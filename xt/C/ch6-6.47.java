import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
/**
 * 102. 二叉树的层序遍历
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 返回其层次遍历结果：
 *
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result=new ArrayList<>();

        if(root==null)
            return result;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()){
            int size=queue.size();
            List<Integer> templist=new ArrayList<>();
            for(int i=0;i<size;i++)
            {
                TreeNode treeNode=queue.remove();
                templist.add(treeNode.val);
                if(treeNode.left!=null)
                    queue.add(treeNode.left);
                if(treeNode.right!=null)
                    queue.add(treeNode.right);
            }
            result.add(templist);

        }
        return result;
    }
}