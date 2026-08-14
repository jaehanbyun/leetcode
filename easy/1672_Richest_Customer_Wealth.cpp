class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        int ans = 0;
        for (int i=0; i<m; ++i) {
            int wealth = 0;
            for (int j=0; j<n; ++j) {
                wealth += accounts[i][j];
            }
            ans = max(ans, wealth);
        }
        return ans;
    }
};