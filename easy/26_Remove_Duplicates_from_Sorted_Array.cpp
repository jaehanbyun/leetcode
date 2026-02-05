class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s(nums.begin(), nums.end());
        // nums = vector<int>(s.begin(), s.end());
        // return s.size();

        int insertIdx = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i]) {
                nums[insertIdx] = nums[i];
                insertIdx++;
            }
        }

        return insertIdx;
    }
};