class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t minLen = strs[0].size();
        for (size_t i = 1; i < strs.size(); ++i)
            minLen = min(minLen, strs[i].size());

        string ans;
        for (int idx = 0; idx < minLen; ++idx) {
            char c = strs[0][idx];
            bool ok = true;
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][idx] != c) { ok = false; break; }
            }
            if (!ok) break;
            ans.push_back(c);
        }
        return ans;
    }
};