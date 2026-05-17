class Solution {
public:
    int findMin(vector<int>& nums) {
        // #1 answer
        // return *min_element(nums.begin(), nums.end());

        // #2 answer
        if (nums.size() == 1) return nums[0];

        int l = 0, r = nums.size() - 1;
        if (nums[r] > nums[0]) return nums[0];

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;          
            else r--;
        }

        return nums[l];
    }
};