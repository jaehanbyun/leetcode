class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int answer = 0;

        for (int r = 1; r < n; ++r) {
            if (prices[r] < prices[l]) {
                l = r;
            } else {
                answer = max(answer, prices[r] - prices[l]);
            }
        }

        return answer;
    }
};