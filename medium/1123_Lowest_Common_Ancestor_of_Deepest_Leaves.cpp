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
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto [ld, lcaL] = dfs(node->left);
        auto [rd, lcaR] = dfs(node->right);

        if (ld == rd) return {ld + 1, node};
        else if (ld > rd) return {ld + 1, lcaL};
        else return {rd + 1, lcaR};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;    
    }
};