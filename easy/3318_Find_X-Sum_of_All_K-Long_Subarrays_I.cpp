static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first != b.first) return a.first > b.first; 
    return a.second > b.second;                       
}

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = (int)nums.size();
        vector<int> answer;
        if (n < k) return answer;

        answer.reserve(n - k + 1);
        unordered_map<int,int> cnt;

        for (int j = 0; j < k; ++j) cnt[nums[j]]++;

        for (int i = 0; i <= n - k; ++i) {
            vector<pair<int,int>> p; 
            p.reserve(cnt.size());
            for (auto& [val, c] : cnt) {
                if (c > 0) p.push_back({c, val});
            }
            sort(p.begin(), p.end(), cmp);

            int xSum = 0;
            int take = min(x, (int)p.size());
            for (int j = 0; j < take; ++j) {
                xSum += p[j].first * p[j].second;
            }
            answer.push_back((int)xSum);

            if (i == n - k) break;

            int outv = nums[i];
            int inv  = nums[i + k];

            if (--cnt[outv] == 0) cnt.erase(outv); 
            cnt[inv]++;                             
        }
        return answer;
    }
};