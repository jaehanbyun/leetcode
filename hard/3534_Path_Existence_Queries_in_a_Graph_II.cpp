class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> nodes;
        for (int i=0; i<n; ++i) {
            nodes.push_back({nums[i], i});
        }
        sort(nodes.begin(), nodes.end());

        vector<int> values(n); // sorted value
        vector<int> pos(n); // original node number -> position after sorting

        for (int i=0; i<n; ++i) {
            values[i] = nodes[i].first;
            pos[nodes[i].second] = i;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            ++LOG;
        }
        
        vector<vector<int>> up(LOG, vector<int>(n));

        // up[0][i] = the rightmost position reachable from i in one step
        int right = 0;
        for (int i=0; i<n; ++i) {
            right = max(right, i);

            while (right + 1 < n && values[right+1] - values[i] <= maxDiff) {
                ++right;
            }

            up[0][i] = right;
        }

        for (int k=1; k<LOG; ++k) {
            for (int i=0; i<n; ++i) {
                up[k][i] = up[k-1][up[k-1][i]];
            }
        }

        vector<int> answer;

       for (const auto& query : queries) {
            int start = pos[query[0]];
            int target = pos[query[1]];

            if (start > target) {
                swap(start, target);
            }

            if (start == target) {
                answer.push_back(0);
                continue;
            }

            int current = start;
            int distance = 0;

            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][current] < target &&
                    up[k][current] > current) {
                    current = up[k][current];
                    distance += (1 << k);
                }
            }

            if (up[0][current] >= target) {
                answer.push_back(distance + 1);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};