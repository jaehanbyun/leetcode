class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i) {
            int targetNum = nums[i];
            for (int j = 1; j < targetNum; ++j) {
                int orNum = j | (j + 1);
                if (orNum == targetNum) {
                    ans[i] = j;
                    break;
                }
            }
        }

        return ans;
    }
};

