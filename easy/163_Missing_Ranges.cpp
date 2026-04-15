class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> ans;

        if (n == 0) {
            ans.push_back({lower, upper});
            return ans;
        }
        
        if (lower < nums[0]) {
            ans.push_back({lower, nums[0]-1});
        }

        for (int i=0; i<n-1; ++i) {
            if (nums[i+1] - nums[i] <= 1) continue;
            ans.push_back({nums[i]+1, nums[i+1]-1});
        }

        if (nums[n-1] < upper) {
            ans.push_back({nums[n-1]+1, upper});
        }

        return ans;
    }
};