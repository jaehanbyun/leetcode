class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) r = mid;
            else l = mid;
        }
        
        if (r < n && nums[r] == target) return r;
        else return -1;
    }
};