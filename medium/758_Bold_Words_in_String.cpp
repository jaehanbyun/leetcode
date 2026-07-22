class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        vector<int> mask(n, 0);
        for (int i=0; i<n; ++i) {
            string prefix = s.substr(i);
            for (string word: words) {
                if (prefix.starts_with(word)) {
                    for (int j=i; j<min(i+(int)word.size(), n); ++j) {
                        mask[j] = 1;
                    }
                }
            }
        }

        string result;
        for (int i=0; i<n; ++i) {
            if (mask[i] && (i==0 || !mask[i-1])) {
                result += "<b>";
            }

            result += s[i];

            if (mask[i] && (i==n-1 || !mask[i+1])) {
                result += "</b>";
            }
        }

        return result;
    }
};