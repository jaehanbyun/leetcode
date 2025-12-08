class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a=1; a<=n; ++a) {
            for (int b=1; b<=n; ++b) {
                int rootC = sqrt(pow(a, 2) + pow(b, 2));
                int c = pow(a, 2) + pow(b, 2);
                if (rootC * rootC == c && rootC <= n) {
                    ans++;
                }
            }
        }
        return ans;
    }
};