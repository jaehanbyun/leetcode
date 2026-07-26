class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return max(nums[0] * nums[1] * nums[2], nums[nums.size()-1] * nums[nums.size()-2] * nums[0]);
    }
};