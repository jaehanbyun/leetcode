class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int k = 0;
        while ((1 << (k + 1)) <= n) ++k;           

        int msb  = 1 << k;                          // 2^k
        int full = (1 << (k + 1)) - 1;              // 2^(k+1) - 1

        return full - minimumOneBitOperations(n ^ msb);
    }
};