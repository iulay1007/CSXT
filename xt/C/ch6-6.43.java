/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 226. 翻转二叉树
 * 翻转一棵二叉树。
 *
 * 示例：
 *
 * 输入：
 *
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 输出：
 *
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * 执行用时：
 * 0 ms
 * , 在所有 Java 提交中击败了
 * 100.00%
 * 的用户
 * 内存消耗：
 * 35.8 MB
 * , 在所有 Java 提交中击败了
 * 87.98%
 * 的用户
 * 一遍过不到五分钟写的简单题，因为实在很简单qwq
 * 
 */
class Solution226 {
    public TreeNode invertTree(TreeNode root) {
        if(root==null)
            return null;
        if(root.left==null&&root.right==null)
            return root;
        TreeNode temp;
        temp=root.left;
        root.left=root.right;
        root.right=temp;
        invertTree(root.left);
        invertTree(root.right);

        return root;

    }
}