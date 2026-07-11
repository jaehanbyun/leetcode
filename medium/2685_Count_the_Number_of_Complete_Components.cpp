class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;

        for (auto& edge: edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        auto bfs = [&](int start) {
            int nodes = 0, edgeEnds = 0;
            queue<int> q;
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                nodes++;
                edgeEnds += graph[u].size();
                for (int v: graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            return (edgeEnds == nodes * (nodes-1));
        };

        for (int i=0; i<n; ++i) {
            if (!visited[i] && bfs(i)) {
                ans++;
            }
        }

        return ans;
    }
};