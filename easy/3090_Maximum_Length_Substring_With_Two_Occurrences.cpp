class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, ans = 0;
        unordered_map<char, int> cnt;
        for (int r=0; r<s.size(); ++r) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 2) {
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};