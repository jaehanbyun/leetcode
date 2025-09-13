class Solution {
public:
    int maxFreqSum(string s) {
        auto isVowel = [](char a) {
            switch (a) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
            default:
                return false;
            }
        };

        unordered_map<char,int> vM, cM;
        int maxVF = 0, maxCF = 0;

        for (char c : s) {
            if (isVowel(c)) {
                maxVF = max(maxVF, ++vM[c]);
            } else {
                maxCF = max(maxCF, ++cM[c]);
            }
        }
        return maxVF + maxCF;
    }
};