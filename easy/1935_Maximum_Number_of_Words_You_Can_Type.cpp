class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words; 
        istringstream iss(text);
        string token;
        while (iss >> token) {
            words.push_back(token);
        }

        unordered_set<char> broken;
        broken.reserve(brokenLetters.size());
        for (auto c: brokenLetters) {
            broken.insert(c);
        }

        int ans = 0;
        for (auto w: words) {
            int flag = 0;
    
            for (auto b: broken) {
                if (w.contains(b)) {
                    flag = 1;
                    break;
                }
            }

            if (!flag) ans++;
        }

        return ans;
    }
};