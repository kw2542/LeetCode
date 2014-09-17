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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stack;
        TreeNode *node = root;
        while (false == stack.empty() || nullptr != node) {
            if (node != nullptr) {
                res.push_back(node->val);
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                node = node->right;
            }
        }
        return res;
    }
};