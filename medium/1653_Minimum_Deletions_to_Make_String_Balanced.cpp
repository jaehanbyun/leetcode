class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> beforeB(n);
        vector<int> afterA(n);

        for (int i = 1; i < n; ++i) {
            if (s[i-1] == 'b') beforeB[i] = beforeB[i-1] + 1;
            else beforeB[i] = beforeB[i-1];
        }

        for (int i = n-2; i >= 0; --i) {
            if (s[i+1] == 'a') afterA[i] = afterA[i+1] + 1;
            else afterA[i] = afterA[i+1];
        }

        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, beforeB[i] + afterA[i]);
        }

        return ans;
    }
};