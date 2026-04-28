class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;

        // flatten the 2D grid into a 1D array
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }

        // after sorting, select the median
        sort(nums.begin(), nums.end());
        int middleNumber = nums[nums.size() / 2];

        // check the remaining condition
        int ans = 0;
        for (int num: nums) {
            if (num % x != middleNumber % x) return -1;
            ans += abs(middleNumber - num) / x;
        }
        return ans;
    }
};