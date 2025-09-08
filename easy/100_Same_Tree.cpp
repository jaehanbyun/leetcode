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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> A, B;
        A.push(p);
        B.push(q);

        while (!A.empty() && !B.empty()) {
            TreeNode* x = A.front(); A.pop();
            TreeNode* y = B.front(); B.pop();

            if ((x == nullptr) != (y == nullptr)) return false;
            if (!x && !y) continue;         

            if (x->val != y->val) return false;

            A.push(x->left);  B.push(y->left);
            A.push(x->right); B.push(y->right);
        }
      
        return A.empty() && B.empty();
    }
};