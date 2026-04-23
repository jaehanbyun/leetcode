class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr;
        arr.resize(n, 0);
        unordered_map<int, vector<int>> m;

        for (int i=0; i<n; ++i) {
            m[nums[i]].push_back(i);
        }

        for (auto& item: m) {
            vector<int> &v = item.second;
            int k = v.size();
            if (k == 1) continue;

            vector<long long> prefSum(k);
            prefSum[0] = v[0];
            for (int i=1; i<k; ++i) {
                prefSum[i] = prefSum[i-1] + v[i];
            }
            
            long long total = prefSum[k-1];
            for (int i=0; i<k; ++i) {
                long long idx = v[i];

                long long left = 0;
                if (i > 0) left = idx * i - prefSum[i-1];
                
                long long right = total - prefSum[i] - idx*(k-1-i);

                arr[idx] = left + right;
            }

        }

        return arr;
    }
};