class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int best = n;
        int right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && nums[right] <= (long long)nums[left] * k) right++;
            best = min(best, n - (right - left));
        }

        return best;
    }
};