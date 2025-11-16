class Solution {
public:
    const long long MOD = 1'000'000'007;
    int numSub(string s) {
        long long res = 0;
        long long cur = 0;

        for (char c: s) {
            if (c == '1') {
                cur++;
                res = (res + cur) % MOD;
            }
            else {
                cur = 0;
            }
        }
        return (int)res;
    }
};