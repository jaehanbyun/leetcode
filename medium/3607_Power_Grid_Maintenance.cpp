class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> graph(c + 1);
        for (auto& e : connections) {
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> compId(c + 1, -1);
        vector<int> visited(c + 1, 0);
        vector<set<int>> compSets;  // 각 컴포넌트의 "온라인 노드" 집합(초기엔 전부 온라인)

        auto bfs = [&](int start, int id) -> set<int> {
            queue<int> q;
            set<int> nodes;
            q.push(start);
            visited[start] = 1;
            compId[start] = id;
            nodes.insert(start);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (visited[v]) continue;
                    visited[v] = 1;
                    compId[v] = id;
                    q.push(v);
                    nodes.insert(v);
                }
            }
            return nodes;
        };

        int id = 0;
        for (int i = 1; i <= c; ++i) {
            if (!visited[i]) {
                compSets.push_back(bfs(i, id));
                ++id;
            }
        }

        vector<int> ans;
        for (const auto& qv : queries) {
            int t = qv[0], x = qv[1];
            int cid = compId[x];

            if (t == 1) {
                auto& S = compSets[cid];
                if (S.count(x)) {
                    ans.push_back(x);
                } else if (!S.empty()) {
                    ans.push_back(*S.begin()); // 같은 컴포넌트 내 최솟값
                } else {
                    ans.push_back(-1);
                }
            } else { // t == 2
                // x를 오프라인 처리
                compSets[cid].erase(x);
            }
        }
        return ans;
    }
};