/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(int num, TreeNode* node) {
        if (node == nullptr) return;

        num = (num << 1) | node->val;

        if (!node->left && !node->right) {
            ans += num;
            return;
        } 

        dfs(num, node->left);
        dfs(num, node->right);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(0, root);
        return ans;
    }
};