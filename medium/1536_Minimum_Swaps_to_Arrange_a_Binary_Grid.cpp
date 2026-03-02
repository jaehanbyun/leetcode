class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRight(n, -1);

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) maxRight[i] = j;
            }
        }

        int ans = 0;

        for (int i=0; i<n; ++i) {
            int target = i;
            while (target < n && maxRight[target] > i) {
                target++;
            }

            if (target == n) return -1;

            ans += target - i;
            while (target > i) {
                swap(maxRight[target], maxRight[target-1]);
                target--;
            }
        }

        return ans;
    }
};