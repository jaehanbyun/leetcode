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
    int count = 0;
    int answer = 0;

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;
    }

    void inorder(TreeNode* node, int k) {
        if (!node || count >= k) return;

        inorder(node->left, k);
        count++;
        if (count == k) {
            answer = node->val;
            return;
        }
        inorder(node->right, k);
    }
};