class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = (int)s.size();
        
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i=0; i<n; ++i) {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = max(last[x], i);
        }

        int ans = 0;

        for (int i=0; i<26; ++i) {
            int l = first[i];
            int r = last[i];

            if (l == n || r == -1 || l >= r) continue;

            bool mid[26] = {false};

            for (int j=l+1; j<r; ++j) {
                mid[s[j]-'a'] = true;
            }

            for (int m=0; m<26; ++m) {
                if (mid[m]) ans++;
            }
        }
     
        return ans;
    }
};