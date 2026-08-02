class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return maxDiff(nums, 0, n-1) >= 0;
    }

    int maxDiff(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        int scoreByLeft = nums[left] - maxDiff(nums, left+1, right);
        int scoreByRight = nums[right] - maxDiff(nums, left, right-1);

        return max(scoreByLeft, scoreByRight);
    }
};