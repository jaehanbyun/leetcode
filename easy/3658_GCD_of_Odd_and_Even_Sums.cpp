class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for (int i=1; i<=n; ++i) {
            int val = 2*i-1;
            odd += val;
            even += val+1;
        }

        return gcd(odd, even);
    }
};