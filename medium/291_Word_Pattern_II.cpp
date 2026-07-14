class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> charToStr;
        unordered_set<string> used;
        return backtrack(pattern, 0, s, 0, charToStr, used);
    }

private:
    bool backtrack(const string& pattern, int pi,
                   const string& s, int si,
                   unordered_map<char, string>& charToStr,
                   unordered_set<string>& used) {
        if (pi == (int)pattern.size() && si == (int)s.size()) return true;
        if (pi == (int)pattern.size() || si == (int)s.size()) return false;

        char c = pattern[pi];

        if (charToStr.count(c)) {
            const string& mapped = charToStr[c];
       
            if (s.compare(si, mapped.size(), mapped) != 0) return false;
            return backtrack(pattern, pi + 1, s, si + mapped.size(), charToStr, used);
        }

        for (int len = 1; si + len <= (int)s.size(); ++len) {
            string candidate = s.substr(si, len);

            if (used.count(candidate)) continue;
     
            charToStr[c] = candidate;
            used.insert(candidate);

            if (backtrack(pattern, pi + 1, s, si + len, charToStr, used))
                return true;

            charToStr.erase(c);
            used.erase(candidate);
        }

        return false;
    }
};
