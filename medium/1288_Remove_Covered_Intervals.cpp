class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int n = intervals.size();
        int ans = n;

        for (int i=n-1; i>=0; --i) {
            int al = intervals[i][0], ar = intervals[i][1];
            for (int j=i-1; j>=0; --j) {
                int bl = intervals[j][0], br = intervals[j][1];
                if (bl <= al && br >= ar) {
                    ans--;
                    break;
                }
            }
        }


        return ans;
    }
};