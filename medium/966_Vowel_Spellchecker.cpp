class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    string devowel(string s) {
        for (char &c : s) {
            char t = tolower(c);
            c = isVowel(t) ? '*' : t;
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lowerMap, devMap;
        exact.reserve(wordlist.size());
        lowerMap.reserve(wordlist.size());
        devMap.reserve(wordlist.size());

        for (auto& w : wordlist) {
            exact.insert(w);
            string lw = toLower(w);
            if (!lowerMap.count(lw)) lowerMap[lw] = w;
            string dw = devowel(w);
            if (!devMap.count(dw)) devMap[dw] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            if (exact.count(q)) { ans.push_back(q); continue; }
            
            string lq = toLower(q);
            auto it1 = lowerMap.find(lq);
            if (it1 != lowerMap.end()) { ans.push_back(it1->second); continue; }
            
            string dq = devowel(q);
            auto it2 = devMap.find(dq);
            if (it2 != devMap.end()) { ans.push_back(it2->second); continue; }
            ans.push_back("");
        }
        return ans;
    }
};
