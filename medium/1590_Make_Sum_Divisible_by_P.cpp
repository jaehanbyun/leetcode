class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = (int)nums.size();
        int total = 0;
        for (int num: nums) {
            total = (total + num) % p;
        }

        int target = total % p;
        if (target == 0) return 0;

        unordered_map<int, int> modMap;
        modMap[0] = -1;
        int currentSum = 0;
        int minLen = n;

        for (int i=0; i<n; ++i) {
            currentSum = (currentSum + nums[i]) % p;
            int needed = (currentSum - target + p) % p;

            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }
            
            modMap[currentSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};