class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            int m = s.size();
            string t;
            t.reserve(m - 1);

            for (int i = 0; i < m - 1; ++i) {
                int d = (s[i] - '0') + (s[i+1] - '0');
                d %= 10;
                t.push_back(d + '0');
            }

            s.swap(t);
        }

        return s[0] == s[1];
    }
};