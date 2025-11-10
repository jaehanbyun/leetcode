class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        st.push_back(0);
        int ans = 0;
        for (int n: nums) {
            while (!st.empty() && st.back() > n) st.pop_back();
            if (st.back() < n && n > 0) {
                st.push_back(n);
                ans++;
            }
        }
        return ans;
    }
};
