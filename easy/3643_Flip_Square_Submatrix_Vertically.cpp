class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i=x, dx=0; i<x+k/2; ++i, ++dx) {
            for (int j=y; j<y+k; ++j) {
                int tmp = grid[i][j];
                grid[i][j] = grid[x+k-1-dx][j];
                grid[x+k-1-dx][j] = tmp;
            }
        }

        return grid;
    }
};