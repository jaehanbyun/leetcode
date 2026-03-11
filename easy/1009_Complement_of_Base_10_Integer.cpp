class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int mask = 0;
        int tmp = n;
        while (tmp > 0) {
            mask = (mask << 1) | 1;
            tmp >>= 1;
        }

        return mask ^ n;
    }
};