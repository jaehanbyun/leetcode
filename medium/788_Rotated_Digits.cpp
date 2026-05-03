class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        unordered_map<int, int> m = {
            {0, 0},
            {1, 1},
            {8, 8},
            {2, 5}, {5, 2},
            {6, 9}, {9, 6},
        };

        auto checkValid = [&](int num) -> bool {
            int t = 0, cnt = 0;
            int tmp = num;

            while (tmp > 0) {
                int x = tmp % 10;
                if (!m.count(x)) return false;
                t += m[x] * pow(10, cnt);
                cnt++;
                tmp /= 10;
            }

            return t != num;
        };
        
        for (int i=1; i<=n; ++i) {
            if (checkValid(i)) {
                cout << i << '\n';
                ans++;
            }
        }

        return ans;
    }
};