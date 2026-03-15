class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;
        int n = workerTimes.size();
        vector<int> r(n, 1);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i=0; i<n; ++i) {
            pq.push({workerTimes[i], i});
        }

        while (mountainHeight > 0) {
            auto [t, w] = pq.top(); pq.pop();
            r[w]++;
            long long nextWorkerTimes = t + (long long)workerTimes[w] * r[w];    
            ans = max(ans, t);
            pq.push({nextWorkerTimes, w});
            mountainHeight--;
        }

        return ans;
    }
}