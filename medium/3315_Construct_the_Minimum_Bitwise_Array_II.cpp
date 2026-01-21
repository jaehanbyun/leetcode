class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if ((x & 1) == 0) continue;

            int t = 0;
            int y = x;
            while (y & 1) {
                t++;
                y >>= 1;
            }

            int sub = 1 << (t - 1);
            ans[i] = x - sub;
        }

        return ans;
    }
};
