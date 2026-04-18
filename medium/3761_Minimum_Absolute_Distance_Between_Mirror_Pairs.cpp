class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last;
        int ans = INT_MAX;

        auto rev = [](int x) {
            int r = 0;
            while (x > 0) {
                r = r * 10 + x % 10;
                x /= 10;
            }
            return r;
        };

        for (int i=0; i<n; ++i) {
           int x = nums[i];

            if (last.count(x)) {
                ans = min(ans, i - last[x]);
            }

            int r = rev(x);
            last[r] = i;
        }

        return (ans == INT_MAX) ? -1: ans;
    }
};