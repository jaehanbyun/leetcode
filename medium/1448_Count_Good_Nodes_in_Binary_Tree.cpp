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
    int cnt = 0;

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return cnt;
    }

    void dfs(TreeNode* node, int maxValInPath) {
        if (!node) return;

        if (node->val >= maxValInPath) {
            maxValInPath = max(node->val, maxValInPath);
            cnt++;
        }

        dfs(node->left, maxValInPath);
        dfs(node->right, maxValInPath);
    }
};