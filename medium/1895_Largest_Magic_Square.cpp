class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rowPS(m, vector<int>(n + 1, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                rowPS[r][c + 1] = rowPS[r][c] + grid[r][c];
            }
        }

        vector<vector<int>> colPS(m + 1, vector<int>(n, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                colPS[r + 1][c] = colPS[r][c] + grid[r][c];
            }
        }

        vector<vector<int>> diag1PS(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                diag1PS[r + 1][c + 1] = diag1PS[r][c] + grid[r][c];
            }
        }

        vector<vector<int>> diag2PS(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = n - 1; c >= 0; --c) {
                diag2PS[r + 1][c] = diag2PS[r][c + 1] + grid[r][c];
            }
        }

        auto rowSum = [&](int r, int c1, int c2) -> int {
            return rowPS[r][c2 + 1] - rowPS[r][c1];
        };

        auto colSum = [&](int c, int r1, int r2) -> int {
            return colPS[r2 + 1][c] - colPS[r1][c];
        };

        auto diag1Sum = [&](int x, int y, int k) -> int {
            return diag1PS[x + k][y + k] - diag1PS[x][y];
        };

        auto diag2Sum = [&](int x, int y, int k) -> int {
            return diag2PS[x + k][y] - diag2PS[x][y + k];
        };

        auto isMagicSquare = [&](int x, int y, int k) -> bool {
            int target = rowSum(x, y, y + k - 1);

            // rows
            for (int i = 0; i < k; ++i) {
                if (rowSum(x + i, y, y + k - 1) != target) return false;
            }

            // cols
            for (int j = 0; j < k; ++j) {
                if (colSum(y + j, x, x + k - 1) != target) return false;
            }

            // diagonals
            if (diag1Sum(x, y, k) != target) return false;
            if (diag2Sum(x, y, k) != target) return false;

            return true;
        };

        int maxSide = min(m, n);
        for (int k = maxSide; k >= 2; --k) { 
            for (int r = 0; r + k <= m; ++r) {
                for (int c = 0; c + k <= n; ++c) {
                    if (isMagicSquare(r, c, k)) return k;
                }
            }
        }
        return 1;
    }
};