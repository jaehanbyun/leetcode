class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // end 오름차순, end 같으면 start 내림차순
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b){
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        int ans = 0;

        int p1 = INT_MIN, p2 = INT_MIN;

        for (auto &in : intervals) {
            int s = in[0], e = in[1];

            if (p2 < s) {
                ans += 2;
                p1 = e - 1;
                p2 = e;
            } 
            else if (p1 < s) {
                ans += 1;
                p1 = p2;
                p2 = e;
            }
        }

        return ans;
    }
};