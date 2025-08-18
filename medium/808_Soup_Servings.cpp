#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0;

        // 컵 개수 N = ceil(n / 25)
        int N = (n + 24) / 25;

        vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1.0));

        function<double(int,int)> f = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;  // 동시에 소진
            if (a <= 0) return 1.0;            // A 먼저 소진
            if (b <= 0) return 0.0;            // B 먼저 소진

            double &res = dp[a][b];
            if (res >= 0.0) return res;        

            res = 0.25 * (
                f(a - 4, b) +        // (100, 0) → 컵 기준 (-4, 0)
                f(a - 3, b - 1) +    // (75, 25) → (-3, -1)
                f(a - 2, b - 2) +    // (50, 50) → (-2, -2)
                f(a - 1, b - 3)      // (25, 75) → (-1, -3)
            );
            return res;
        };

        return f(N, N);
    }
};
