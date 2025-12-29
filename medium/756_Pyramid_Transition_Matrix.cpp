class Solution {
public:
    unordered_map<string, string> t;   
    unordered_map<string, bool> memo;    

    bool dfs(const string& row) {
        if (row.size() == 1) return true;          
        if (memo.count(row)) return memo[row];     

        string next(row.size() - 1, '?');            

        bool ok = buildNextRow(row, next, 0);
        memo[row] = ok;
        return ok;
    }

    bool buildNextRow(const string& row, string& next, int i) {
        if (i == (int)next.size()) {
            return dfs(next);
        }

        string key;
        key.push_back(row[i]);
        key.push_back(row[i + 1]);

        if (!t.count(key)) return false;

        for (char c : t[key]) {
            next[i] = c;
            if (buildNextRow(row, next, i + 1)) return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string& s : allowed) {
            string key = s.substr(0, 2); 
            char top = s[2];              
            t[key].push_back(top);
        }

        return dfs(bottom);
    }
};