class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = 0;
        for (int i = 0; i < nums.size()/2; ++i) {
            best = max(best, nums[i] + nums[nums.size() - i - 1]);
        }
 
        return best;
    }
};
