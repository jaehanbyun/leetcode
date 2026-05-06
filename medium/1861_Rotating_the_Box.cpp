class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> afterBoxGrid(n, vector<char>(m, '.'));

        // 1. rotate 90 degrees
        // 1-1. transpose boxGrid
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (boxGrid[i][j] != '.') {
                    afterBoxGrid[j][i] = boxGrid[i][j];
                }
            }
        }

        // 1-2. reverse eash rows
        for (int i=0; i<n; ++i) {
            reverse(afterBoxGrid[i].begin(), afterBoxGrid[i].end());
        }

        // 2. Fall down each stone
        for (int j = 0; j < m; ++j) {    
            int write = n - 1;           
            for (int i = n - 1; i >= 0; --i) {   
                if (afterBoxGrid[i][j] == '*') {
                    write = i - 1;
                } else if (afterBoxGrid[i][j] == '#') {
                    afterBoxGrid[i][j] = '.';
                    afterBoxGrid[write][j] = '#';
                    --write;
                }
            }
        }

        return afterBoxGrid;
    }
};