class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> graph(numCourses);

        for (auto prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        } 

        queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int nodeVisited = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            nodeVisited++;

            for (auto& neibor: graph[node]) {
                inDegree[neibor]--;
                if (inDegree[neibor] == 0) q.push(neibor);
            }
        }

        return nodeVisited == numCourses;
    }
};