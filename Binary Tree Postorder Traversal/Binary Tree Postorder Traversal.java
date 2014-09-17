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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList();
        TreeNode prev = null;
        Stack<TreeNode> stack = new Stack();
        while (false == stack.isEmpty() || null != root) {
            if (null != root) {
                stack.push(root);
                root = root.left;
            } else {
                TreeNode peek = stack.peek();
                if (null != peek.right && prev != peek.right) {
                    root = peek.right;
                } else {
                    res.add(peek.val);
                    stack.pop();
                    prev = peek;
                }
            }
        }
        return res;
    }
}