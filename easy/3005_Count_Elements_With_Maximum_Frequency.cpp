class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0, maxF = 0;
        unordered_map<int, int> m;

        for (const auto& n: nums) {
            m[n]++;
            maxF = max(m[n], maxF);
        }

        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second == maxF) ans += maxF;
        }

        return ans;
    }
};