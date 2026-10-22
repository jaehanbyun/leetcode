class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        bool inc = true, dec = true;
        for (int i=0; i<n; ++i) {
            int cur = nums[i];
            int nxt = nums[(i+1)%n];

            if (nxt != (cur+1) % n) inc = false;
            if (nxt != (cur-1+n) % n) dec = false;
        }

        if (!inc && !dec) return -1;

        int ans = INT_MAX;
        if (inc) {
            int k = nums[0];
            if (k == 0) ans = 0;
            else ans = min(n-k, k+2);
        }

        if (dec) {
            int q = 0;
            for (int i=0; i<n; ++i) {
                if (nums[i] == 0) q = i;
            }

            int p = (q+1) % n;

            ans = min(ans, min(p + 1, n - q));
        }

        return ans;
    }
};