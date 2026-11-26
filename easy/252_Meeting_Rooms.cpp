class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Sort by start time (ties fall back to end time automatically)
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); ++i) {
            int prevEnd  = intervals[i - 1][1];
            int curStart = intervals[i][0];
            // Overlap if the next meeting starts before the previous one ends
            if (curStart < prevEnd) return false;
        }
        return true;
    }
};