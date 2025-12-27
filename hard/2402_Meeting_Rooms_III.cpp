class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        // (endTime, room)
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> busy;

        vector<long long> cnt(n, 0);

        for (auto& mt: meetings) {
            long long start = mt[0];
            long long end = mt[1];
            long long dur = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                cnt[room]++;
                busy.push({end, room});
            }
            else {
                auto [freeTime, room] = busy.top();
                busy.pop();
                cnt[room]++;
                busy.push({freeTime + dur, room});
            }
        }

        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (cnt[i] > cnt[ans]) ans = i; 
        }
        return ans;
    }
};
