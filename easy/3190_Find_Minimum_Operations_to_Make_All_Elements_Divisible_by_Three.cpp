class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int x: nums) {
            int t = x % 3;
            ans += min(t, 3 - t);
        }
        return ans;
    }
};