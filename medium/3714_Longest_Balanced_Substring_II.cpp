class Solution {
public:
    int longestBalanced(string s) {
        // handle base case
        int n = s.length();
        if (n <= 2) return n;

        int res = 1;
        // handle single character case
        int prev = s[0];
        int cnt = 1;
        for (int i=1; i<n; ++i) {
            if (s[i] == prev) {
                cnt++;
                res = max(res, cnt);
            }
            else {
                prev = s[i];
                cnt = 1;
            }
        }
        
        // handle two characters case
        vector<pair<char, char>> tc = {
            {'a', 'b'}, {'b', 'c'}, {'c', 'a'}
        };
        
        for (auto t: tc) {
            char c1 = t.first;
            char c2 = t.second;
            char other = 'a' + 'b' + 'c' - c1 - c2;

            unordered_map<int, int> m2;
            m2[0] = -1;
            int diff = 0;

            for (int i=0; i<n; ++i) {
                if (s[i] == other) {
                    m2.clear();
                    m2[0] = i;
                    diff = 0;
                }
                else {
                    if (s[i] == c1) diff++;
                    else diff--;

                    if (m2.count(diff)) res = max(res, i - m2[diff]);
                    else m2[diff] = i;
                }
            }
        }

        // handler three characters case
        vector<int> ps(3, 0);
        map<vector<int>, int> m3;
        m3[{0, 0, 0}] = -1;

        for (int i=0; i<n; ++i) {
            ps[s[i]-'a']++;
            
            int nps = *min_element(ps.begin(), ps.end());
            vector<int> mn = {
                ps[0] - nps,
                ps[1] - nps,
                ps[2] - nps
            };

            if (m3.count(mn)) res = max(res, i - m3[mn]);
            else m3[mn] = i;
        }

        return res;
    }
};
