class Solution {
public:
    int totalMoney(int n) {
        int totalMoney = 0;
        for (int i = 1; i <= n; ++i) {
            int week = (i - 1) / 7;
            int day = (i - 1) % 7; 
            totalMoney += (week + 1) + day;
        }
        return totalMoney;
    }
};

