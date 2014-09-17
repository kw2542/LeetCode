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
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }
    int height(TreeNode *root) {
        if (nullptr == root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (-1 == left || -1 == right || 1 < abs(left - right)) return -1;
        else return left >  right? left + 1 : right + 1;
        
    }
};