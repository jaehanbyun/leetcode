class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int nl = nums.size(), ql = queries.size();
        unordered_map<int, vector<int>> hm;
        vector<int> answer;
        
        if (ql == 0) return answer;

        for (int i=0; i<nl; ++i) {
            hm[nums[i]].push_back(i);
        }

        for (auto& [a, b]: hm) {
            int x = b[0];
            b.insert(b.begin(), b.back() - nl);
            b.push_back(x + nl);
        }

        for (int i=0; i<ql; ++i) {
            int qi = queries[i];
            int num = nums[qi];

            if (hm[num].size() <= 3) {
                answer.push_back(-1);
                continue;
            }

            auto it = lower_bound(hm[num].begin(), hm[num].end(), qi);
            int idx = it - hm[num].begin();

            answer.push_back(min(abs(hm[num][idx] - hm[num][idx-1]), abs(hm[num][idx] - hm[num][idx+1])));
        }

        return answer;
    }
};