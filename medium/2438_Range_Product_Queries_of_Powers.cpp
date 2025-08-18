class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long MOD = 1'000'000'007LL;

        vector<long long> powers;
        for (int i = 0; i < 31; ++i) {
            if (n & (1 << i)) powers.push_back(1LL << i);
        }

        vector<int> answers;
        answers.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long long prod = 1;
            for (int j = l; j <= r; ++j) {
                prod = (prod * (powers[j])) % MOD;
            }
            answers.push_back((int)prod);
        }
        return answers;
    }
};
