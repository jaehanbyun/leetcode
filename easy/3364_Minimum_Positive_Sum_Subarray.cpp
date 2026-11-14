class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> prefix = buildPrefix(nums);

        int ans = findMinPositive(prefix, l, r);
        
        return (ans == INT_MAX) ? -1 : ans;
    }

private:
    // prefix[i] = nums[0] + ... + nums[i-1]  (0-based, 크기 n+1)
    vector<int> buildPrefix(const vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return prefix;
    }

    int findMinPositive(const vector<int>& prefix, int l, int r) {
        int n = prefix.size() - 1;
        int best = INT_MAX;

        for (int len = l; len <= r; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int sum = prefix[i + len] - prefix[i];  
                if (sum > 0) {
                    best = min(best, sum);              
                }
            }
        }
        return best;
    }
};