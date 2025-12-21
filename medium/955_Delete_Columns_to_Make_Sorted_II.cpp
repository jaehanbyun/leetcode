class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deletions = 0;

        int n = strs.size();
        int m = strs[0].size();
        
        // sorted[i] == str[i] < str[i] 관계가 확정된 상태
        vector<bool> sorted(n-1, false);

        for (int col = 0; col < m; ++col) {
            bool bad = false;

            for (int i = 0; i < n-1; ++i) {
                if (sorted[i]) continue;
                if (strs[i][col] > strs[i+1][col]) {
                    bad = true;
                    break;
                }
            } 

            if (bad) {
                deletions++;
                continue;
            }

             for (int i = 0; i < n-1; ++i) {
                if (sorted[i]) continue;
                if (strs[i][col] < strs[i+1][col]) {
                    sorted[i] = true;
                }
            } 

            bool allSort = true;
            for (bool s: sorted) {
                if (!s) {
                    allSort = false;
                    continue;
                }
            }
            if (allSort) break;
        }
        

        return deletions;
    }
};