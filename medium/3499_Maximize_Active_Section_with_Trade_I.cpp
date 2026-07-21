class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<pair<char,int>> seg;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            seg.push_back({s[i], j - i});
            i = j;
        }

        int total1 = count(s.begin(), s.end(), '1');
        int gain = 0;
        for (int k = 0; k + 2 < (int)seg.size(); k++) {
            if (seg[k].first == '0' && seg[k+1].first == '1' && seg[k+2].first == '0') {
                gain = max(gain, seg[k].second + seg[k+2].second);
            }
        }
        return total1 + gain;
    }
};
