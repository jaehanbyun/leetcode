class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            int mx = 0, sum = 0;
            int j = i;
            while (j < n && colors[i] == colors[j]){
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            ans += (sum - mx);
            i = j;
        }
        return ans;
    }
};
