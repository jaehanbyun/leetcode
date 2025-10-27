class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();

        vector<int> numberOfDivice;
        numberOfDivice.reserve(m);

        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (bank[i][j] == '1') {
                    cnt++;
                }
            }
            numberOfDivice.push_back(cnt);
        }

        int ans = 0;
        int prev = 0;
        for (int i = 0; i < m; ++i) {
            int curr = numberOfDivice[i];
            if (curr == 0) continue;
            ans += prev * curr;
            prev = curr;
        }

        return ans;
    }
};
