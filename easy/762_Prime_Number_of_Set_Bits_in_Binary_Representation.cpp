class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        int prime[21] = {
            0,0,1,1,0,1,0,1,0,0,0,
            1,0,1,0,0,0,1,0,1,0
        };

        for (int i=left; i<=right; ++i) {
            int bits = __builtin_popcount(i);
            if (prime[bits]) ans++;
        }

        return ans;
    }
};