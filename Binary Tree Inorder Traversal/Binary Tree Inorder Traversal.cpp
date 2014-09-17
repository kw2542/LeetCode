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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stack;
        TreeNode *node = root;
        while (false == stack.empty() || node != nullptr) {
            if (node != nullptr) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};