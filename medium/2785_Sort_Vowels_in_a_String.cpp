class Solution {
public:
    string sortVowels(string s) {
        vector<char> vec(s.size(), ' ');
        vector<char> vowels;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E' && s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O'
                && s[i] != 'u' && s[i] != 'U') {
                vec[i] = s[i];
            }
            else {
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (vec[i] == ' ') {
                vec[i] = vowels[idx];
                idx++;
            }
        }

        string ans(vec.begin(), vec.end());
        return ans;
    }
};