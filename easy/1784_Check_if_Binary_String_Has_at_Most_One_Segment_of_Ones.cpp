class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i=1; i<s.size(); ++i) {
            if (s[i] != s[i-1]) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }
};