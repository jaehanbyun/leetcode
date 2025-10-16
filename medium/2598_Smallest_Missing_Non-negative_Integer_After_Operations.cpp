class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);

        for (long long n : nums) { 
            int r = (int)(((n % value) + value) % value); 
            cnt[r]++;
        }

        int ans = 0;
        while (cnt[ans % value] > 0) {
            cnt[ans % value]--;
            ans++;
        }
        return ans;
    }
};
