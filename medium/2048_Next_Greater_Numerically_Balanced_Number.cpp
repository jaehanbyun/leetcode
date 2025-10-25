class Solution {
public:
    int nextBeautifulNumber(int n) {
        int x = n + 1;

        auto isBalanced = [&](int num) -> bool{
            int cnt[10] = {0};
            int y = num;
            while (y > 0) {
                int d = y % 10;
                if (d == 0) return false;
                cnt[d]++;
                y /= 10;
            }
            for (int i = 1; i <= 9; ++i) {
                if (cnt[i] != 0 && cnt[i] != i) return false;
            }
            return true;
        };

        while (true) {
            if (isBalanced(x)) return x;
            x++;
        }
    }
};
