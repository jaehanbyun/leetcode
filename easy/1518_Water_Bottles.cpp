class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int add = empty / numExchange;        
            ans += add;                           
            empty = add + (empty % numExchange);  
        }
        return ans;
    }
};