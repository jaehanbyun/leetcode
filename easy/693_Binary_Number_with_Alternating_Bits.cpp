class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n & 1;
        while (n > 0) {
            n = n >> 1;
            int msb = n & 1;
            if (prevBit == msb) {
                return false;
            }
            prevBit = n & 1;
        }
        return true;
    }
};