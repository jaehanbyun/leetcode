class Solution {
public:
    int popcount(long long x) {
        int c = 0;
        while (x) {
            x &= (x - 1); 
            ++c;
        }
        return c;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; ++k) {
            long long R = (long long)num1 - (long long)k * (long long)num2;

            if (R < 0) {
                if (num2 > 0) break; 
                continue;          
            }

            if ((long long)k > R) continue; 

            int pc = popcount((long long)R); 
            if (pc <= k) return k; 
        }
        return -1;
    }
};
