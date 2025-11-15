class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size();
        vector<int> nextZero(n, n);
        for (int i = n - 2; i >= 0; --i) {
            if (s[i+1] == '0') {
                nextZero[i] = i + 1;
            }
            else {
                nextZero[i] = nextZero[i + 1];
            }
        }

        int answer = 0;
        for (int l = 0; l < n; ++l) {
            int zeroes = s[l] == '0' ? 1 : 0;
            int r = l;

            while (zeroes * zeroes <= n) {
                int nextZ = nextZero[r];
                int ones = (nextZ - l) - zeroes;
                if (ones >= zeroes * zeroes) {
                    answer += min(nextZ - r, ones - zeroes * zeroes + 1);
                }
                r = nextZ;
                zeroes++;

                if (r == n) break;
            }
        }

        return answer;
    }
};