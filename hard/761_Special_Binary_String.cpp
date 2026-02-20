class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;

        vector<string> mountains;
        int height = 0;
        int start = 0;

        for (int i = 0; i < s.size(); ++i) {
            height += (s[i] == '1') ? 1 : -1;

            if (height == 0) {
                string inner = s.substr(start+1, i - start - 1);
                string processed = "1" + makeLargestSpecial(inner) + "0";
                mountains.push_back(processed);
                start = i+1;
            }
        }

        sort(mountains.begin(), mountains.end(), greater<string>());

        string result;
        for (auto& m : mountains) result += m;
        return result;
    }
};