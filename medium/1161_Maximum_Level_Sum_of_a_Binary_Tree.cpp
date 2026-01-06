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
    int maxLevelSum(TreeNode* root) {
        // key: level, value: the sum of each level
        map<int, int> m; 

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [curr, lv] = q.front(); q.pop();
            m[lv] += curr->val;
            
            if (curr->left != nullptr) {
                q.push({curr->left, lv + 1});
            }
            if (curr->right != nullptr) {
                q.push({curr->right, lv + 1});
            }
        }

        int ans = 0;
        int sum = -1e9;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second > sum) {
                ans = iter->first;
                sum = iter->second;
            }
        }

        return ans;
    }
};