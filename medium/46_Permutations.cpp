class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visit.assign(nums.size(), false);
        dfs(nums);
        return res;
    }

private:
    vector<bool> visit;
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
        }

        for (int i=0; i<nums.size(); ++i) {
            if (visit[i]) continue;
            visit[i] = true;
            cur.push_back(nums[i]);
            dfs(nums);
            cur.pop_back();
            visit[i] = false;
        }
    }
};