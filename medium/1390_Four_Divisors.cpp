class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            int cnt = 2;
            int divisorSum = 1 + num;
            for (int i = 2; 1LL * i * i <= num; ++i) {
                if (num % i != 0) continue;
                
                if (i == num / i) {
                    cnt = -1;
                    break;
                }

                divisorSum += i + num / i;
                cnt += 2;

                if (cnt > 4) break;
            }
            if (cnt == 4) {
                ans += divisorSum;
            }
        }

        return ans;
    }
};



