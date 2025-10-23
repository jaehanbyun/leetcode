class Solution {
public:
    int romanToInt(string s) {
        int m = s.size();
        unordered_map<char, int> r = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int ans = 0, prev = 0;
        for (int i = m - 1; i >= 0; --i) {
            int v = r[s[i]];
            if (v < prev) ans -= v;
            else { ans += v; prev = v; }
        }
        
        return ans;
    }
};