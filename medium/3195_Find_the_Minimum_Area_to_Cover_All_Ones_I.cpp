class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int minR = n, maxR = -1, minC = m, maxC = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    minR = min(minR, i);
                    maxR = max(maxR, i);
                    minC = min(minC, j);
                    maxC = max(maxC, j);
                }
            }
        }
        
        int height = maxR - minR + 1;
        int width  = maxC - minC + 1;
        return height * width;
    }
};