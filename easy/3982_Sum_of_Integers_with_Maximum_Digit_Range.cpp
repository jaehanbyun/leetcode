class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int rangeSum[10] = {0};
        int maxRange = 0;

        for (int num: nums) {
            string s = to_string(num);
            int lo = *min_element(s.begin(), s.end());
            int hi = *max_element(s.begin(), s.end());
            int r = hi - lo;

            rangeSum[r] += num;
            maxRange = max(maxRange, r);
        }
        
        return rangeSum[maxRange];
    }
};