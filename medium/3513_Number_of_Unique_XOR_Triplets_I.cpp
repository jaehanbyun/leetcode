class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        int result = 1;
        while (result <= n) {
            result <<= 1;
        }
        return result;
    }
};