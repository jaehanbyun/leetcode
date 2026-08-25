class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto& num: nums) {
            map[num]++;
        }

        vector<vector<int>> bucket(nums.size()+1);
        for (auto& [k, v]: map) {
            bucket[v].push_back(k);
        }

        vector<int> answer;
        for (int freq=bucket.size()-1; freq>0 && answer.size()<k; --freq) {
            for (int i=0; i<bucket[freq].size(); ++i) {
                answer.push_back(bucket[freq][i]);
                if (answer.size() == k) return answer;
            }
        }
        return answer;
    }
};