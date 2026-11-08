class Solution {
private:
    // (weight, index)
    using FreeNode = pair<int, int>;
    // (end time, weight, index)
    using BusyNode = tuple<long long, int, int>;

    priority_queue<FreeNode, vector<FreeNode>, greater<FreeNode>> freePQ;
    priority_queue<BusyNode, vector<BusyNode>, greater<BusyNode>> busyPQ;

    void initServers(vector<int>& servers) {
        for (int i=0; i<servers.size(); ++i) {
            freePQ.push({servers[i], i});
        }
    }

    void releaseServers(long long t) {
        while (!busyPQ.empty() && get<0>(busyPQ.top()) <= t) {
            auto [endTime, weight, index] = busyPQ.top();
            busyPQ.pop();
            freePQ.push({weight, index});
        }
    }

    long long decideStartTime(long long t) {
        releaseServers(t);

        if (freePQ.empty()) {
            t = get<0>(busyPQ.top());   
            releaseServers(t);          
        }

        return t;
    }

    int assign(long long t, int duration) {
        auto [weight, index] = freePQ.top();
        freePQ.pop();

        busyPQ.push({t+duration, weight, index});
        return index;
    }
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = tasks.size();
        vector<int> ans(m);

        initServers(servers);

        long long t = 0; 

        for (int j=0; j<m; ++j) {
            t = max(t, (long long)j);
            t = decideStartTime(t);  
            ans[j] = assign(t, tasks[j]);
        }

        return ans;
    }
};