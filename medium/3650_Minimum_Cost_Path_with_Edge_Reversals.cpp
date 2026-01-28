class Solution {
    using pii = pair<int, int>;
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> graph(n);
        for (auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w * 2});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> queue;
        dist[0] = 0;
        queue.push({0, 0});

        while (!queue.empty()) {
            int node = queue.top().second;
            queue.pop();
            if (node == n - 1) return dist[node];

            for (auto [nextNode, nextW]: graph[node]) {
                if (dist[node] + nextW < dist[nextNode]) {
                    dist[nextNode] = dist[node] + nextW;
                    queue.push({dist[nextNode], nextNode});
                }
            }
        }

        return -1;
    }
};