class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> validWords;
        string longestValidWord = "";
        for (string& word: words) {
            if (word.length() == 1 || validWords.find(word.substr(0, word.length()-1)) != validWords.end()) {
                validWords.insert(word);

                if (longestValidWord.length() < word.length()) longestValidWord = word;
            }
        }
        return longestValidWord;
    }
};