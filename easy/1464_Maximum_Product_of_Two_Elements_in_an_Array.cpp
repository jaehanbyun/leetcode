class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 1. sort
        // sort(nums.begin(), nums.end(), greater<int>());
        // return (nums[0] - 1) * (nums[1] - 1);

        // 2. biggest, second biggest
        int biggest = 0;
        int secondBiggest = 0;
        for (int num: nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(num, secondBiggest);
            }
        }
        return (biggest-1) * (secondBiggest-1);
    }
};