class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        if (vec == nums) return 0;

        int ans = 0;
        while (true) {
            int minPairSum = INT_MAX;
            int start = 0;
            int end = 0;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (minPairSum > nums[i] + nums[i + 1]) {
                    minPairSum = nums[i] + nums[i + 1];
                    start = i;
                    end = i + 1;
                }
            }
            ans++;
            nums[start] = minPairSum;
            nums.erase(nums.begin() + end);
            vector<int> vec = nums;
            sort(vec.begin(), vec.end());
            if (vec == nums) return ans;
        }

        return 0;
    }
};