class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        if (costs[0] > coins) return 0;

        int n = costs.size();
        int iceCream = 0;
        while(iceCream < n && costs[iceCream] <= coins) {
            coins -= costs[iceCream];
            iceCream++;
        }

        return iceCream;
    }
};