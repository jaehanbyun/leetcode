class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0, nums, cur, res);
        return res;
    }

    void dfs(int i, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i+1, nums, cur, res);

        cur.pop_back();
        dfs(i+1, nums, cur, res);
    }
};