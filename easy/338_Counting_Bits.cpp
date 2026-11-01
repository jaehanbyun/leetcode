class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int x = 0;
        int b = 1;

        // [0, b) is calculated
        while (b <= n) {
            // generate [b, 2b) or [b, n) from [0, b)
            while (x < b && x + b <= n) {
                ans[x + b] = ans[x] + 1;
                x++;
            }
            x = 0;
            b <<= 1;
        }
        
        return ans;
    }
};