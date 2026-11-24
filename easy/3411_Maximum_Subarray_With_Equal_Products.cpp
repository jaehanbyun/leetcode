class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        const long long LIMIT = 2520LL * 10;

        for (int i=0; i<n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j=i; j<n; ++j) {
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (prod > LIMIT) break;
                if (prod == l * g) ans = max(ans, j - i + 1); 
            }
        }
        return ans;
    }
};