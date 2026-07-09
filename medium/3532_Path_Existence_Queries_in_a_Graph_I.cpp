class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        for (int i=1; i<n; ++i) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                comp[i] = comp[i-1];
            } else {
                comp[i] = comp[i-1] + 1;
            }
        }
        
        vector<bool> answer;
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            answer.push_back(comp[u] == comp[v]);
        }
        return answer;
    }
};