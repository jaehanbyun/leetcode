class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r + 2 < m; ++r) {
            for (int c = 0; c + 2 < n; ++c) {
                if (isMagicSquare(grid, r, c)) res++;
            }
        }

        return res;
    }

    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<bool> seen(10, false);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int n = grid[row+i][col+j];
                if (n < 1 || n > 9) return false;
                if (seen[n]) return false;
                seen[n] = true;
            }
        }

        int diagonal1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2]; 
        int diagonal2 = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];
        if (diagonal1 != diagonal2) return false;

        int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];

        if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal2)) return false;

        int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];

        if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal2)) return false;

        return true;
    }
};