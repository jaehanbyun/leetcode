class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i=0; i<s1.size(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int match = 0;
        for (int i=0; i<26; ++i) {
            if (s1Count[i] == s2Count[i]) {
                match++;
            }
        }

        if (match == 26) return true;

        int l = 0;
        for (int r=s1.size(); r<s2.size(); ++r) {
            if (match == 26) return true;

            int idx = s2[r] - 'a';

            s2Count[idx]++;
            if (s1Count[idx] == s2Count[idx]) {
                match++;
            } else if (s1Count[idx] + 1 == s2Count[idx]) {
                match--;
            }

            idx = s2[l] - 'a';

            s2Count[idx]--;
            if (s1Count[idx] == s2Count[idx]) {
                match++;
            } else if (s1Count[idx] - 1 == s2Count[idx]) {
                match--;
            }
            l++;
        }

        return match == 26;
    }
};