class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));

        for (int i=0; i<m-k+1; ++i) {
            for (int j=0; j<n-k+1; ++j) {
                set<int> s;
                for (int x=0; x<k; ++x) {
                    for (int y=0; y<k; ++y) {
                        s.insert(grid[i+x][j+y]);
                    }
                }
                int best = INT_MAX;
                if (s.size() >= 2) {
                    auto it = s.begin();
                    auto prev = it;
                    it++;
                    for (; it != s.end(); ++it, ++prev) {
                        best = min(best, *it - *prev);
                    }
                }
                else best = 0;
                
                ans[i][j] = best == INT_MAX ? 0 : best;
            }
        }

        return ans;
    }
};