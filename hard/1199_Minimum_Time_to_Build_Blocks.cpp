class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int time : blocks) {
            pq.push(time);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();
            int mergedTime = max(a, b) + split;
            pq.push(mergedTime);
        }

        return pq.top();
    }
};