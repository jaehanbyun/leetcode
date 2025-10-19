class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int N = s.size();
        queue<string> q;
        unordered_set<string> vis;

        vis.insert(s);
        q.push(s);

        string ans = s;

        auto addOdds = [&](string t) -> string {
             for (int i = 1; i < N; i += 2) {
                t[i] = ((t[i] - '0' + a) % 10) + '0';
            }
            return t;
        };

        auto rotateRightB = [&](string t) -> string {
            rotate(t.begin(), t.begin() + (N - b), t.end());
            return t;
        };

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur < ans) ans = cur;

            string op1 = addOdds(cur);
            if (!vis.count(op1)) { vis.insert(op1); q.push(op1); }

            string op2 = rotateRightB(cur);
            if (!vis.count(op2)) { vis.insert(op2); q.push(op2); }
        }
        return ans;
    }
};