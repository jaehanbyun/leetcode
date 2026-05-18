class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> m;
        queue<int> q;

        for (int i=0; i<n; ++i) {
            m[arr[i]].push_back(i);
        }

        q.push(0);
        visited[0] = true;
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int pos = q.front();
                q.pop();

                if (pos == n-1) return step;
                
                for (auto item: m[arr[pos]]) {
                    if (!visited[item]) {
                        visited[item] = true;
                        q.push(item);
                    }
                }

                m[arr[pos]].clear();

                for (auto x: {pos-1, pos+1}) {
                    if (0 <= x && x < n && !visited[x]) {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
            
            step += 1;
        }

        return -1;
    }
};