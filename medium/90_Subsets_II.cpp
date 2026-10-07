class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    set<vector<int>> res;
    vector<int> cur;

    void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.insert(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i + 1, nums);

        cur.pop_back();
        dfs(i + 1, nums);
    }
};