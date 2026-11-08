class Solution {
private:
    void countRowsAndCols(const vector<vector<int>>& grid,
                          vector<int>& rowCnt, vector<int>& colCnt) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
    }

    int countConnected(const vector<vector<int>>& grid,
                       const vector<int>& rowCnt, const vector<int>& colCnt) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (rowCnt[i] > 1 || colCnt[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }

public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCnt(m, 0), colCnt(n, 0);

        countRowsAndCols(grid, rowCnt, colCnt);       
        return countConnected(grid, rowCnt, colCnt); 
    }
};