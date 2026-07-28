class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        vector<int> cnt(26, 0);
        for (int i=0; i<n/2; ++i) {
            cnt[s[i] - 'a']++;
        }

        int left = 0, right = n - 1;
        
        for (int i=0; i<26; ++i) {
            while (cnt[i] > 0) {
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
                cnt[i]--;
            }
        }
       
        return s;
    }
};