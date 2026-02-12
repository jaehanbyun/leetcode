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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        createInorder(inorder, root);
        return inorder;
    }
private:
    void createInorder(vector<int>& inorder, TreeNode* node) {
        if (node == nullptr) return;

        createInorder(inorder, node->left);
        inorder.push_back(node->val);
        createInorder(inorder, node->right);
    }
};
