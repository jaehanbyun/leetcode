class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int pos = q.front();
            q.pop();

            if (arr[pos] == 0) return true;

            int next1 = pos + arr[pos];
            int next2 = pos - arr[pos];

            if (next1 >= 0 && next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }

            if (next2 >= 0 && next2 < n && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }

        return false;
    }
};