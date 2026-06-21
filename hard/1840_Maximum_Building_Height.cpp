class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i=1; i<m; ++i) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(
                restrictions[i-1][1] + dist,
                restrictions[i][1]
            );
        }

        for (int i=m-2; i>=0; --i) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(
                restrictions[i+1][1] + dist,
                restrictions[i][1]
            );
        }

        int ans = 0;

        for (int i=1; i<m; ++i) {
            int l = restrictions[i-1][0];
            int hl = restrictions[i-1][1];
            int r = restrictions[i][0];
            int hr = restrictions[i][1];

            int dist = r - l;
            int diff = abs(hr - hl);

            int peak = max(hr, hl) + (dist - diff) / 2;
            ans = max(ans, peak);
        }

        return ans;
    }
};