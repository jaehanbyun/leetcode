class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9+7;
        unordered_map<int, int> pointsSet;
        long long ans = 0, sum = 0;
        for (auto point: points) {
            pointsSet[point[1]]++;
        }

        for (auto point: pointsSet) {
            long long sideNum = (long long)point.second * (point.second-1) / 2;
            ans += sideNum * sum;
            sum += sideNum;
        }

        return ans % mod;
    }
};