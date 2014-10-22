/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int sumNumbers(TreeNode root) {
        return sumNumbers(root, 0);
    }
    private int sumNumbers(TreeNode root, int i) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return i * 10 + root.val;
        else return sumNumbers(root.left, 10 * i + root.val) + sumNumbers(root.right, 10 * i + root.val);
    }
}