class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minTime = 0;
        vector<int> curr = points[0];
        for (int i = 1; i < points.size(); ++i) {
            int xgap = abs(curr[0] - points[i][0]);
            int ygap = abs(curr[1] - points[i][1]);

            minTime += max(xgap, ygap);

            curr = points[i];
        }

        return minTime;
    }
};