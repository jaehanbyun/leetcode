class Solution {
public:
    const double EPS = 1e-6;

     bool dfs(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                vector<double> next;
                next.reserve(n - 1);
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                // a + b
                next.push_back(a + b);
                if (dfs(next)) return true;
                next.pop_back();

                // a - b
                next.push_back(a - b);
                if (dfs(next)) return true;
                next.pop_back();

                // a * b
                next.push_back(a * b);
                if (dfs(next)) return true;
                next.pop_back();

                // a / b (0으로 나누기 방지)
                if (fabs(b) > EPS) {
                    next.push_back(a / b);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};
