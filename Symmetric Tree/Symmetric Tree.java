/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) : val(x), left(null), right(null) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode left, TreeNode right) {
        if (left == null && right == null) return true;
        else if (left == null) return false;
        else if (right == null) return false;
        else if (left.val != right.val) return false;
        else return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
};