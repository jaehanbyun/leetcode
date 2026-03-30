class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char, int> even;
        map<char, int> odd;
        int n = s1.length();

        for (int i=0; i<n; ++i) {
            if (i % 2 == 0) even[s1[i]]++;
            else odd[s1[i]]++;
        }

        for (int i=0; i<n; ++i) {
            if (i % 2 == 0) {
                if (even.find(s2[i]) == even.end()) return false;
                else {
                    if (even[s2[i]]) even[s2[i]]--;
                    else return false;
                }
            }
            else {
                if (odd.find(s2[i]) == odd.end()) return false;
                else {
                    if (odd[s2[i]]) odd[s2[i]]--;
                    else return false;
                }
            }
        }

        return true;
    }
};