class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int NEG = -1e9;
        vector<int> dp(3, NEG);
        dp[0] = 0; 

        for (int x : nums) {
            vector<int> ndp = dp;  
            int m = x % 3;

            for (int r = 0; r < 3; ++r) {
                if (dp[r] == NEG) continue;  
                int nr = (r + m) % 3;
                ndp[nr] = max(ndp[nr], dp[r] + x);
            }
            
            dp.swap(ndp);
        }

        return dp[0];
    }
};
