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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> parents, childs;
        unordered_map<int, vector<pair<int, int>>> parentToChild;

        for (auto& d: descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            parents.insert(parent); parents.insert(child);
            childs.insert(child);
            parentToChild[parent].push_back({child, isLeft});
        }

        TreeNode* root;
        for (auto it=parents.begin(); it!=parents.end(); ++it) {
            if (childs.count(*it) == 0) {
                root = new TreeNode(*it);
            }
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front(); q.pop();

            for (auto& childInfo: parentToChild[parent->val]) {
                int childVal = childInfo.first, isLeft = childInfo.second;
                TreeNode* child = new TreeNode(childVal);
                if (isLeft == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
                q.push(child);
            }  
        } 

        return root;
    }
};