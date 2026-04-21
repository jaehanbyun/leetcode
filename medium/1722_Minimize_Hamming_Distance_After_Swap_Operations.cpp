class Solution {
public:
    vector<int> parents;
    vector<int> rank;

    int find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parents[px] = py;
        } else if (rank[px] > rank[py]) {
            parents[py] = px;
        } else {
            parents[py] = px;
            rank[px]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int distance = 0;

        parents.resize(n);
        rank.resize(n, 0);

        for (int i=0; i<n; ++i) {
            parents[i] = i;
        }
        for (auto& p: allowedSwaps) {
            merge(p[0], p[1]);
        }
        unordered_map<int, unordered_map<int, int>> s;
        for (int i=0; i<n; ++i) {
            int f = find(i);
            s[f][source[i]]++;
        }

        for (int i=0; i<n; ++i) {
            int f = find(i);
            if (s[f][target[i]] > 0) s[f][target[i]]--;
            else distance++;
        }

        return distance;
    }
};

