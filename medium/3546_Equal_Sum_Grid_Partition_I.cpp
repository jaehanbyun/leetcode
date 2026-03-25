class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> sum(m+1, vector<long long>(n+1));

        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i-1][j-1];
            } 
        }

        for (int r=1; r<m+1; ++r) {
            long long r1 = sum[r][n];
            long long r2 = sum[m][n] - sum[r][n];
            
            if (r1 == r2) return true;
        }

        for (int c=1; c<n+1; ++c) {
            long long c1 = sum[m][c];
            long long c2 = sum[m][n] - sum[m][c];

            if (c1 == c2) return true;
        }

        return false;
    }
};