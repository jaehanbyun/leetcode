class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = (int)nums.size();
        vector<bool> ans(n);
        int rem = 0;  

        for (int i=0; i<n; ++i) {
            rem = (rem * 2 + nums[i]) % 5;
            ans[i] = (rem == 0);
        }
        return ans;
    }
};
