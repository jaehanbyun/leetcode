class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> s(arr.begin(), arr.end());
        
        unordered_map<int, int> rank;
        int r = 1;
        for (int x: s) {
            rank[x] = r++;
        }

        vector<int> answer;
        answer.reserve(n);
        for (int x: arr) {
            answer.push_back(rank[x]);
        }
        return answer;
    }
};