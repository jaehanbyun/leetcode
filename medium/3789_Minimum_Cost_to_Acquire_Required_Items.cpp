class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;

        if (need1 > need2) {
            swap(need1, need2);
            swap(cost1, cost2);
        }

        totalCost += (long long)min(cost1+cost2, costBoth) * need1;
        totalCost += (long long)min(costBoth, cost2) * (need2 - need1);

        return totalCost;
    }
};