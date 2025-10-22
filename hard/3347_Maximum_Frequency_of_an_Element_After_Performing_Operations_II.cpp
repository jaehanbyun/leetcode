class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k, long long numOperations) {
        int n = (int)nums.size();
        unordered_map<long long, long long> counter;
        sort(nums.begin(), nums.end());

        for (long long num: nums) {
            counter[num]++;
        }

        auto go = [&](long long num) -> long long {
            auto leftIndex = lower_bound(nums.begin(), nums.end(), num - k);
            auto rightIndex = upper_bound(nums.begin(), nums.end(), num + k);

            long long tmp = min(numOperations, (rightIndex - leftIndex) - counter[num]);
            return counter[num] + tmp;
        };

        vector<long long> events;
        for (int num: nums) {
            events.push_back(num - k);
            events.push_back(num);
            events.push_back(num + k);
        }

        sort(events.begin(), events.end());

        long long best = 0LL;
        for (long long num: events) {
            best = max(best, go(num));
        }
        
        return (int)best;
    }
};
