class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int s=0; s<k; ++s) {
            vector<vector<int>> newGrid(m, vector<int>(n));

            for (int i=0; i<m; ++i) {
                for (int j=0; j<n-1; ++j) {
                    newGrid[i][j+1] = grid[i][j];
                }
            }

            for (int i=0; i<m-1; ++i) {
                newGrid[i+1][0] = grid[i][n-1];
            }

            newGrid[0][0] = grid[m-1][n-1];
            grid = newGrid;
        }
        
        return grid;
    }
};