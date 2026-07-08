
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1'000'000'007;
        int m = s.length();

        vector<long long> pow10(m + 1);
        pow10[0] = 1;
        for (int i = 1; i <= m; ++i)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        vector<long long> P(m + 1, 0);
        vector<int> cnt(m + 1, 0), sum(m + 1, 0);

        for (int i = 0; i < m; ++i) {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            if (d != 0) {
                P[i + 1] = (P[i] * 10 + d) % MOD;   
                cnt[i + 1] = cnt[i] + 1;
            } else {
                P[i + 1] = P[i];
                cnt[i + 1] = cnt[i];
            }
        }

        vector<int> answer;
        for (auto& q : queries) {
            int l = q[0], r = q[1]; 

            int k = cnt[r + 1] - cnt[l];
            if (k == 0) {             
                answer.push_back(0);
                continue;
            }

            long long x = (P[r + 1] - P[l] * pow10[k]) % MOD;
            x = (x % MOD + MOD) % MOD;         

            long long digitSum = sum[r + 1] - sum[l];
            answer.push_back((int)(x * (digitSum % MOD) % MOD));
        }

        return answer;
    }
};   