class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), 
            [](vector<int>& a, vector<int>& b) {
                long long gapA = (long long)a[1] - a[0];
                long long gapB = (long long)b[1] - b[0];

                return gapA > gapB;
            });

        int ans = 0;
        int cur = 0;

        for (auto& task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if (cur < minimum) {
                ans += minimum - cur;
                cur = minimum;
            }

            cur -= actual;
        }

        return ans;

    }
};