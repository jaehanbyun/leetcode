class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zeroCount = 0; 
        int best = 0;

        for (int right=0; right<n; ++right) {
            addRight(nums[right], zeroCount);
            shrinkUntilValid(nums, left, zeroCount);
            best = max(best, right - left + 1);
        }

        return best;
    }

private:
    void addRight(int num, int& zeroCount) {
        if (num == 0) zeroCount++;
    }

    void shrinkUntilValid(vector<int>& nums, int& left, int& zeroCount) {
        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
    }
};