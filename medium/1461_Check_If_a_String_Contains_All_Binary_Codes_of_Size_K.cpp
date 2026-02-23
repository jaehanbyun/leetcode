class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;

        int allBinaryCodesNum = pow(2, k);
        unordered_set<string> binaryCodes;
        
        for (int i=0; i<s.length()-k+1; ++i) {
            binaryCodes.insert(s.substr(i, k));
        }

        return binaryCodes.size() == allBinaryCodesNum;
    }
};