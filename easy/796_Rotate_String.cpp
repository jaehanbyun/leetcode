class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s == goal) return true;
        int n = s.size();
        for (int i=1; i<n; ++i) {
            string t;
            for (int j=0; j<n; ++j) {
                t += s[(j+i)%n];
            }
            if (t == goal) return true;
        }
        return false;
    }
};