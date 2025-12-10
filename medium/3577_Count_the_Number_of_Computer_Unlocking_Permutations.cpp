class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0]) {
            return 0;
        }

        const long long mod = 1'000'000'007 * 1LL;
        int n = complexity.size();

        auto factorial = [](auto self, long long num) -> long long {
            if (num == 0 || num == 1) return 1;
            else return num * self(self, num - 1) % mod;
        };

        return factorial(factorial, n-1) % mod;
    }
};

