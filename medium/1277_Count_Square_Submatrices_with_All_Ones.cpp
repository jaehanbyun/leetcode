class Solution {
public:
    int rect_sum(const vector<vector<int>>& P, int r1, int c1, int r2, int c2) {
        return P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1];
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxSquareSize = min(m, n);
        int ans = 0;

        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        for (int k = 1; k <= maxSquareSize; k++) {
            int squareSize = k * k;
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i + k - 1 <= m && j + k - 1<= n) {
                        int tempSize = rect_sum(prefixSum, i, j, i + k - 1, j + k - 1);
                        if (tempSize == squareSize) ans += 1;
                    }
                }
            }
        }
       
        return ans;
    }
};