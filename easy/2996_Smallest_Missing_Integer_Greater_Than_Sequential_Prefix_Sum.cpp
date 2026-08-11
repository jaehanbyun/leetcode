class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];
    
        for (int i=1; i<n; ++i) {
            if (nums[i] == nums[i-1] + 1) {
                s += nums[i];
            } else break;
        }
        
        unordered_set<int> st(nums.begin(), nums.end());
        int x = s;
        while (st.count(x)) ++x;
        return x;
    }
};