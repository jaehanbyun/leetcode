class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> distict;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                bool flag = true;
                distict[s[j]]++;

                for (auto iter = distict.begin(); iter != distict.end(); ++iter) {
                    if (iter->second > 0 && iter->second != distict[s[j]]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) ans = max(ans, (j - i) + 1);
            }
        }

        return ans;
    }
};
