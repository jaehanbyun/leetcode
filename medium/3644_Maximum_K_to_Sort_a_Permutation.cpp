class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans = -1;

        for (int i=0; i<n; ++i) {
            if (isInPlace(nums, i)) continue;

            ans &= nums[i];
        }

        return ans == -1 ? 0 : ans;
    }

private:
    bool isInPlace(vector<int>& nums, int i) {
        return nums[i] == i;
    }
};