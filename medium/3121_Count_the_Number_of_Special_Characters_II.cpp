class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        int n = word.size();
        unordered_map<char, int> m;

        for (int i=0; i<n; ++i) {
            if ('A' <= word[i] && word[i] <= 'Z') {
                if (!m.count(word[i])) {
                    m[word[i]] = i;
                }
            } else {
                m[word[i]] = i;
            }
        }

        for (char c='a'; c<='z'; ++c) {
            if (m.count(c) && m.count(c - 32) && m[c] < m[c - 32]) {
                ans++;
            }
        }

        return ans;
    }
};