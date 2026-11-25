class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int cur = 0;
        for (int x: nums) {
            cur = max(x, cur + x);
            best = max(best, cur);
        }
        return best;
    }
};