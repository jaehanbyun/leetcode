class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        dfs(0, candidates, target);

        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(int start, vector<int>& candidates, int remain) {
        if (remain == 0) {
            res.push_back(cur);
            return;
        }

        for (int j=start; j<candidates.size(); ++j) {
            if (j > start && candidates[j] == candidates[j-1]) continue;
            if (candidates[j] > remain) break;

            cur.push_back(candidates[j]);
            dfs(j+1, candidates, remain - candidates[j]);
            cur.pop_back();
        }
    }
};