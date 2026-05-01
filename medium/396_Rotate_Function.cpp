class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int F = 0;
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i=0; i<n; ++i) {
            F += i*nums[i];
        }
        int res = F;
        for (int k=n-1; k>0; --k) {
            F += numSum - n*nums[k];
            res = max(F, res);
        }
        return res;
    }
};