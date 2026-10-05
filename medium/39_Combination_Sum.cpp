class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(vector<int>& c, int start, int remain) {
        if (remain == 0) {
            res.push_back(cur);
            return;
        }

        for (int i=start; i<c.size(); ++i) {
            if (c[i] > remain) break;
            cur.push_back(c[i]);
            dfs(c, i, remain - c[i]);
            cur.pop_back();
        }
    }
};