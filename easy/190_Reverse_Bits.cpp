class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int power = 31;
        int idx = 0;
        while (n != 0) {
            ans += (n & 1) << power;
            n = n >> 1;
            power--;
        }
        return ans;
    }
};