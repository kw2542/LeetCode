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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
    TreeNode *sortedArrayToBST(vector<int> &num, int s, int e) {
        if (s > e) return NULL;
        int mid = (s + e) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = sortedArrayToBST(num, s, mid - 1);
        node->right = sortedArrayToBST(num, mid + 1, e);
        return node;
    }
};