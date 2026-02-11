/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x)f, left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(inorder, root);
        int size = inorder.size();
        return createBST(inorder, 0, size - 1);;
    }
private:
    void inorderTraversal(vector<int>& inorder, TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(inorder, node->left);
        inorder.push_back(node->val);
        inorderTraversal(inorder, node->right);
    }

    TreeNode* createBST(vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;    

        int mid = start + (end - start) / 2;

        TreeNode* leftSubTree = createBST(inorder, start, mid - 1);
        TreeNode* rightSubTree = createBST(inorder, mid + 1, end);

        return new TreeNode(inorder[mid], leftSubTree, rightSubTree);
     }
};
