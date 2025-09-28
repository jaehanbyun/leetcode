class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int s = nums.size();
        sort(nums.begin(), nums.end());

        for (int k = s - 1; k >= 2; --k) {
            int a = nums[k-2], b = nums[k-1], c = nums[k];
            if (a + b > c) return a + b + c;
        }

        return 0;
    }
};