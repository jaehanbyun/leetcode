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
    vector<long long> sums;

    long long treeSum(TreeNode *node) {
        if (node == nullptr) return 0;
        long long leftSum = treeSum(node->left);
        long long rightSum = treeSum(node->right);
        long long totalSum = leftSum + rightSum + node->val;
        sums.push_back(totalSum);
        return totalSum;
    }

    int maxProduct(TreeNode* root) {
        const long long MOD = 1e9 + 7;
        
        long long res = 0;
        long long totalSum = treeSum(root);
        
        for (long long s: sums) {
            res = max(res, ((totalSum - s) * s)); 
        }
        
        return (int)(res % MOD);
    }
};