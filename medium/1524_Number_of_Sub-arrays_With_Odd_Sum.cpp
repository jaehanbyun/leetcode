class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> prefix(n+1, 0);
        for (int i=0; i<n; ++i) {
            prefix[i+1] = prefix[i] + arr[i];
        }

        long long evenCnt = 1;
        long long oddCnt = 0;
        long long ans = 0;
        for (int j=1; j<=n; ++j) {
            if (prefix[j] % 2) {
                ans += evenCnt;
                oddCnt++;
            } else {
                ans += oddCnt;
                evenCnt++;
            }
            ans %= MOD;
        }

        return (int)ans;
    }
};