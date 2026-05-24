class Solution {
public:
    vector<int> dp;

    void dfs(vector<int>& arr, int idx, int d, int n) {
        if (dp[idx] != -1) return;

        dp[idx] = 1;

        for (int i=idx-1; i>=0 && idx-i<=d && arr[idx]>arr[i]; --i) {
            dfs(arr, i, d, n);
            dp[idx] = max(dp[idx], dp[i]+1); 
        }

        for (int i=idx+1; i<n && i-idx<=d && arr[idx]>arr[i]; ++i) {
            dfs(arr, i, d, n);
            dp[idx] = max(dp[idx], dp[i]+1); 
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        if (n <= 1) return 1;

        dp.resize(n, -1);

        for (int i=0; i<n; ++i) {
            dfs(arr, i, d, n);
        }

        return *max_element(dp.begin(), dp.end());
    }
};