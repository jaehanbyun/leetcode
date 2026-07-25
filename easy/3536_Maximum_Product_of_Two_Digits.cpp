class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        while (n >= 1) {
            nums.push_back(n % 10);
            n /= 10;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[0] * nums[1];
    }
};