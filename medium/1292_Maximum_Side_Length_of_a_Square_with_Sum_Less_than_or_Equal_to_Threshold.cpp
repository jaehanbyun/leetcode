class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ps(m+1, vector<int>(n+1,0));

        for (int r = 1; r <= m; ++r) {
            for (int c = 1; c <= n; ++c) {
                ps[r][c] = ps[r-1][c] + ps[r][c-1] - ps[r-1][c-1] + mat[r-1][c-1];
            }
        }

        auto rectSum = [&](int r1, int c1, int r2, int c2) -> int {
            return ps[r2+1][c2+1] - ps[r2+1][c1] - ps[r1][c2+1] + ps[r1][c1];
        };

        auto ok = [&](int len) -> bool {
            if (len == 0) return true;
            for (int r = 0; r + len <= m; ++r) {
                for (int c = 0; c + len <= n; ++c) {
                    int r2 = r + len - 1;
                    int c2 = c + len - 1;
                    if (rectSum(r, c, r2, c2) <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n);
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2; 
            if (ok(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};