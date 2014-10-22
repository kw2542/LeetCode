/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) return true;
        else if (left == NULL) return false;
        else if (right == NULL) return false;
        else if (left->val != right ->val) return false;
        else return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};