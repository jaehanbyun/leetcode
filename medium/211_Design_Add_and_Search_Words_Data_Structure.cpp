struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class WordDictionary {
    TrieNode* root = new TrieNode();
public:
    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            int i = c - 'a';
            if (!cur->children[i]) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, 0, word);
    }
    
    bool dfs(TrieNode* node, int idx, const string& word) {
        if (idx == word.size()) return node->isEnd;

        char c = word[idx];
        if (c == '.') {
            for (int k = 0; k < 26; ++k) {
                if (node->children[k] && dfs(node->children[k], idx + 1, word)) {
                    return true;   
                }
            }
            return false;         
        } else {
            int i = c - 'a';
            if (!node->children[i]) return false;
            return dfs(node->children[i], idx + 1, word);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */