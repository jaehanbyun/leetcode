class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        int lowOdd = (low % 2 == 1) ? low : low + 1;
        int highOdd = (high % 2 == 1) ? high : high - 1;
        if (lowOdd == highOdd) return 1;
        return (highOdd - lowOdd - 2) / 2 + 2;
    }
};