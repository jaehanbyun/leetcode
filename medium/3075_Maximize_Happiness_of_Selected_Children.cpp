class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // hs = happinessSum
        long long hs = 0;
        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), greater<int>());

        for (int i = 0; i < k; ++i) {
            long long cur = (long long)happiness[i] - i;
            if (cur <= 0) break;
            hs += cur;
        } 

        return hs;
    }
};