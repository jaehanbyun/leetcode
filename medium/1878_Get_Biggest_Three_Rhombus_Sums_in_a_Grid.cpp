class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<long long, greater<long long>> s;

       
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // k = 0 (셀 하나짜리 마름모)
                s.insert(grid[i][j]);

                // 가능한 최대 반지름
                int maxK = min({i, j, m - 1 - i, n - 1 - j});

                // k >= 1 마름모들
                for (int k = 1; k <= maxK; ++k) {
                    long long sum = 0;

                    // 1) 위 -> 오른쪽 아래 (위쪽 꼭짓점 포함, 오른쪽 꼭짓점 제외)
                    for (int t = 0; t < k; ++t) {
                        int x = i - k + t;
                        int y = j + t;
                        sum += grid[x][y];
                    }

                    // 2) 오른쪽 -> 아래 왼쪽 (오른쪽 꼭짓점 포함, 아래 꼭짓점 제외)
                    for (int t = 0; t < k; ++t) {
                        int x = i + t;
                        int y = j + k - t;
                        sum += grid[x][y];
                    }

                    // 3) 아래 -> 왼쪽 위 (아래 꼭짓점 포함, 왼쪽 꼭짓점 제외)
                    for (int t = 0; t < k; ++t) {
                        int x = i + k - t;
                        int y = j - t;
                        sum += grid[x][y];
                    }

                    // 4) 왼쪽 -> 위 오른쪽 (왼쪽 꼭짓점 포함, 위쪽 꼭짓점 제외)
                    for (int t = 0; t < k; ++t) {
                        int x = i - t;
                        int y = j - k + t;
                        sum += grid[x][y];
                    }

                    s.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (long long v : s) {
            ans.push_back((int)v);
            if ((int)ans.size() == 3) break;
        }
        return ans;
    }
};