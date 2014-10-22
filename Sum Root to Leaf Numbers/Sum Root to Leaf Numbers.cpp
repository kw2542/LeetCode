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
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode *root, int i) {
        if (root == NULL) return 0;
        if (root.left == NULL && root.right == NULL) return i * 10 + root.val;
        else return sumNumbers(root.left, 10 * i + root.val) + sumNumbers(root.right, 10 * i + root.val);
    }
};