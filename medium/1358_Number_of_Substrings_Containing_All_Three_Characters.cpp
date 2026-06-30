class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3);
        int l = 0, ans = 0;

        for (int r=0; r<s.size(); ++r) {
            count[s[r] - 'a']++;
            
            while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[l] - 'a']--;
                l++;
            }

            ans += l;
        }

        return ans;
    }
};