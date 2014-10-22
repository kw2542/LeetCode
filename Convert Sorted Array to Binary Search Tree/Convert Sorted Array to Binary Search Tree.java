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
    public TreeNode sortedArrayToBST(int[] num) {
        return sortedArrayToBST(num, 0, num.length - 1);
    }
    private TreeNode sortedArrayToBST(int[] num, int s, int e) {
        if (s > e) return null;
        int mid = (s + e) / 2;
        TreeNode node = new TreeNode(num[mid]);
        node.left = sortedArrayToBST(num, s, mid - 1);
        node.right = sortedArrayToBST(num, mid + 1, e);
        return node;
    }
}