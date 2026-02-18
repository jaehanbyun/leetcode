class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 2;

        long long f1 = NEG, f2 = NEG, f3 = NEG;
        long long ans = NEG;

        for (int i = 1; i < n; ++i) {
            long long nf1 = NEG, nf2 = NEG, nf3 = NEG;

            if (nums[i] > nums[i - 1]) {
                nf1 = max((long long)nums[i - 1] + nums[i], f1 + nums[i]);
                nf3 = max(f2 + nums[i], f3 + nums[i]);
            } else if (nums[i] < nums[i - 1]) {
                nf2 = max(f1 + nums[i], f2 + nums[i]);
            }

            f1 = nf1;
            f2 = nf2;
            f3 = nf3;

            ans = max(ans, f3);
        }

        return ans;
    }
};
