class Solution {
public:
    int binaryGap(int n) {
        int prevIdx = -1;
        int ans, idx = 0;
        while (n > 0) {
            if (n & 1) {
                if (prevIdx != -1) {
                    ans = max(ans, idx - prevIdx);
                }
                prevIdx = idx;
            }
            n = n >> 1;
            idx++;
        }
        return ans;
    }
};