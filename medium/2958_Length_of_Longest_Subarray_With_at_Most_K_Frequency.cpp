class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> cnt;
        int l = 0;
        for (int r=0; r<n; ++r) {
            cnt[nums[r]]++;
            while (cnt[nums[r]] > k) {
                cnt[nums[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};