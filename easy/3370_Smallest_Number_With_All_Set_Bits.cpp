class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0, num = 1;
        for (int i = 0; i < 11; ++i) {
            if (num > n) {
                ans =  num - 1;
                break;
            }
            num *= 2;
        }

        return ans;
    }
};