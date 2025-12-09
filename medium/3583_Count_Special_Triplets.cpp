class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1'000'000'007LL;
        int n = nums.size();
        unordered_map<int, int> freqLeft;
        unordered_map<int, int> freqRight;
        for (int num: nums) {
            freqRight[num]++;
        }

        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int currentNum = nums[j];

            freqRight[currentNum]--;

            long long l = freqLeft.count(currentNum * 2) ? freqLeft[currentNum * 2] : 0;
            long long r = freqRight.count(currentNum * 2) ? freqRight[currentNum * 2] : 0;
            ans = (ans + l * r) % MOD;

            freqLeft[currentNum]++;
        }

        return ans % MOD;
    }
};