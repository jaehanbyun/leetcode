class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n+1, 0);

        for (int i=1; i<n+1; ++i) {
            ps[i] = nums[i-1] + ps[i-1];
        }

        int ans = 0;
        for (int i=1; i<n; ++i) {
            int a = ps[i];
            int b = ps[n] - ps[i];
            if ((b-a)%2==0) ans++;
        }
        return ans;
    }
};