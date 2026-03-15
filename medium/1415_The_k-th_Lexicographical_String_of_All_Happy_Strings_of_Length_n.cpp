class Solution {
public:
    void dfs(int n, string &cur, vector<string>& result) {
        if (cur.size() == n) {
            result.push_back(cur);
            return;
        }

        for (char ch: {'a', 'b', 'c'}) {
            if (!cur.empty() && cur.back() == ch) continue;
            cur.push_back(ch);
            dfs(n, cur, result);
            cur.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> list;
        string cur;
        dfs(n, cur, list);

        if (list.size() < k) return "";
        return list[k-1];
    }
};