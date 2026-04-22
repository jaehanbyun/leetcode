class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int qLen = queries.size(), dLen = dictionary.size();
        vector<string> ans;

        for (int i=0; i<qLen; ++i) {
            string q = queries[i];
            for (int j=0; j<dLen; ++j) {
                string s = dictionary[j];
                int diffCnt = 0;
                for (int k=0; k<s.size(); ++k) {
                    if (q[k] != s[k]) diffCnt++;
                }
                if (diffCnt <= 2) {
                    ans.push_back(q);
                    break;
                }
             }
        }

        return ans;
    }
};