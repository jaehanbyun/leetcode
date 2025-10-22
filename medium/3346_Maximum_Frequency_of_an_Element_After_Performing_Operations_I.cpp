class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = (int)nums.size();
        unordered_map<long long, int> counter;
        sort(nums.begin(), nums.end());

        for (long long num: nums) {
            counter[num]++;
        }

        auto go = [&](long long num) {
            auto leftIndex = lower_bound(nums.begin(), nums.end(), num - k);
            auto rightIndex = upper_bound(nums.begin(), nums.end(), num + k);

            auto tmp = min(numOperations, (int)(rightIndex - leftIndex) - counter[num]);
            return counter[num] + tmp;
        };

        int best = 0;
        for (int i = 0; i < nums.back() + k + 1; ++i) {
            best = max(best, go(i));
        }
        
        return (int)best;
    }
};