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
private:
    unordered_set<TreeNode*> visited;

    bool isInvalid(TreeNode* node) {
        return node->right != nullptr && visited.find(node->right) != visited.end();
    }

    TreeNode* dfs(TreeNode* node) {
        if (node == nullptr) return node;

        if (isInvalid(node)) {
            return nullptr;
        }

        visited.insert(node);
        node->right = dfs(node->right);
        node->left = dfs(node->left);

        return node;
    }

public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        return dfs(root);
    }
};