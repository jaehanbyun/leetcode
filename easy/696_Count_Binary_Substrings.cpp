class Solution {
public:
    int group[100000] = {1};
    int countBinarySubstrings(string s) {
        int n = s.length();
        int size = 1;
        group[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i-1] == s[i]) group[size-1]++;
            else group[size++]=1;
        } 
        int ans = 0;
        for (int i=1; i<size; ++i) {
            ans += min(group[i], group[i-1]);
        }
        return ans;
    }
};