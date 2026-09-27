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
    TreeNode* invertTree(TreeNode* root) {
        // BFS
        // if (!root) return nullptr;
        // queue<TreeNode*> queue;
        // queue.push(root);

        // while (!queue.empty()) {
        //     TreeNode* node = queue.front();
        //     queue.pop();

        //     swap(node->left, node->right);
        //     if (node->left) queue.push(node->left);
        //     if (node->right) queue.push(node->right);
        // }
        
        // return root;

        // DFS
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};