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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stack;
        TreeNode *node = root;
        TreeNode *prev = nullptr;
        while (false == stack.empty() || nullptr != node) {
            if (nullptr != node) {
                stack.push(node);
                node = node->left;
            } else {
                TreeNode *peek = stack.top();
                if (nullptr != peek->right && prev != peek->right) {
                    node = peek->right;
                } else {
                    res.push_back(peek->val);
                    stack.pop();
                    prev = peek;
                }
            }
        }
        return res;
    }
};