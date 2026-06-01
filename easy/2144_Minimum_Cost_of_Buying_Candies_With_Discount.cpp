class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;

        sort(cost.begin(), cost.end(), greater<int>());

        int idx = 0;
        int cnt = 0;
        while (idx < cost.size()) {
            if (cnt == 2) {
                idx++;
                cnt = 0;
                continue;
            }
            ans += cost[idx++];
            cnt++;
        }

        return ans;
    }
};