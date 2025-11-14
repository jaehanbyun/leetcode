class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n + 1, 0));

        for (const auto& q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            for (int i = r1; i <= r2; ++i) {
                diff[i][c1] += 1;
                if (c2 + 1 < n) diff[i][c2 + 1] -= 1;
            }
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                cur += diff[i][j];
                ans[i][j] = cur;
            }
        }

        return ans;
    }
};
