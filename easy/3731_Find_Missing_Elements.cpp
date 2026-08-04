class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missingElements;
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] != nums[i-1] + 1) {
                int s = nums[i-1] + 1;
                while (s < nums[i]) {
                    missingElements.push_back(s++);
                }
            }
        }
        return missingElements;
    }
};