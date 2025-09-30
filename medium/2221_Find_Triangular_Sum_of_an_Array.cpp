class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int len = n - 1; len > 0; --len) {
            for (int j = 0; j < len; ++j) {
                int x = (nums[j] + nums[j + 1]) % 10;
                nums[j] = x;
            }
        }
        return nums[0];
    }
};