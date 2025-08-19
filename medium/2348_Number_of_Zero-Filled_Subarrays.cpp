class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0, run = 0;

        for (int x: nums) {
            if (x == 0) answer += ++run;
            else run = 0;
        }

        return answer;
    }
};