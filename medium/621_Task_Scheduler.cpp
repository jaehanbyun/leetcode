class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        priority_queue<int> maxHeap;

        for (char task: tasks) {
            cnt[task - 'A']++;
        }

        for (int i=0; i<26; ++i) {
            if (cnt[i] > 0) {
                maxHeap.push(cnt[i]);        
            }
        }

        // {remaining cnt, next available time}
        queue<pair<int, int>> q;

        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        
        return time;        
    }
};