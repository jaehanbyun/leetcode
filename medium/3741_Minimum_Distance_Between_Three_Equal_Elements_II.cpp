class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, int> prev1;
        unordered_map<int, int> prev2;
        int ans = INT_MAX;

        for (int i=0; i<nums.size(); ++i) {
            int v = nums[i];
            prev1.try_emplace(v, -1);
            prev2.try_emplace(v, -1);
            if (prev2[v] != -1) {
                ans = min(ans, 2*(i - prev2[v]));
            }
            prev2[v] = prev1[v];    
            prev1[v] = i;
        }
           
        return ans == INT_MAX ? -1: ans;
    }
};