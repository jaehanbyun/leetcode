class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        for (auto& q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            while (l <= r) {
                long long a = nums[l] % MOD;
                long long b = v % MOD;
                nums[l] = (int)((a * b) % MOD); 
                l += k;
            }
        }

        int ans = nums[0];
        for (int i = 1; i<n; ++i) {
            ans ^= nums[i];
        }
        return ans;
    }
};