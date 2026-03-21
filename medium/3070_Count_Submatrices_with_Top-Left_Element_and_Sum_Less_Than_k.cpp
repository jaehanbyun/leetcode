class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1));

        int ans = 0;
        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i-1][j-1];
                if (sum[i][j] <= k) ans++;
            }
        }

        return ans;
    }
};