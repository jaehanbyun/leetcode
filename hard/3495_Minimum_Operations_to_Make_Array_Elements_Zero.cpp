class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        // p4[k] = 4^k, k = 0,1,2..
        vector<long long> p4;
        p4.push_back(1);
        while (p4.back() <= 1000000000LL) p4.push_back(p4.back() * 4LL);

        long long ans = 0;

        for (auto& query: queries) {
            long long l = query[0], r = query[1];
            long long S = 0; // total required count each interval
            long long M = 0; // max required count

            for (int k = 1; k < (int)p4.size(); ++k) {
                if (p4[k-1] > r) break;

                long long LK = max(l, p4[k-1]);
                long long RK = min(r, p4[k]-1);
                if (LK <= RK) {
                    long long cnt = RK - LK + 1;
                    S += 1LL * k * cnt;
                    if (M < k) M = k;
                }
            }

            ans += max(M, (S + 1)/2);
        }

        return ans;

    }   
};