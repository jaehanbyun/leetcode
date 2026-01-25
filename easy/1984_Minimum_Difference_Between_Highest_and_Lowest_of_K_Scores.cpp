class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());
        int best = nums[k-1] - nums[0];
        for (int r = k; r < nums.size(); ++r) {
            best = min(best, nums[r] - nums[r - k + 1]);
        }

        return best;
    }
}; 