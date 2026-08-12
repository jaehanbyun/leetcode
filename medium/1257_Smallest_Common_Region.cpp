class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // child -> parent map construction
        unordered_map<string, string> parent;
        for (auto& r: regions) {
            for (int i=1; i<r.size(); ++i) {
                parent[r[i]] = r[0];
            }
        } 

        unordered_set<string> ancestors;
        string cur = region1;
        while (true) {
            ancestors.insert(cur);
            if (parent.find(cur) == parent.end()) break;
            cur = parent[cur];
        }

        cur = region2;
        while (ancestors.find(cur) == ancestors.end()) {
            cur = parent[cur];
        }
        return cur;
    }
};
