class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        
        int l = 0;
        int answer = 0;
        for (int r=0; r<n; ++r) {
            count[s[r]]++;

            while (count[s[r]] >= 2) {
                count[s[l]]--;
                l++;
            }

            answer = max(answer, r - l + 1);
        }

        return answer;
    }
};                      