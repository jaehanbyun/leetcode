class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        map<int, vector<vector<int>>> graph;

        for (auto& road: roads) {
            int a = road[0], b = road[1], dist = road[2];
            graph[a].push_back({b, dist});
            graph[b].push_back({a, dist});
        }

        set<int> s;
        s.insert(1);
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int city = q.front(); q.pop();

            for (auto& adj: graph[city]) {
                int adjCity = adj[0];
                if (visited[adjCity]) continue;
                visited[adjCity] = true;
                q.push(adjCity);
                s.insert(adjCity);
            }
        }

        int ans = INT_MAX;
        for (auto x: s) {
            for (auto& adj: graph[x]) {
                ans = min(ans, adj[1]);
            }
        }
    
        return ans;
    }
};