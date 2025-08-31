class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx; // 값 -> 인덱스
        idx.reserve(nums.size());

        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            auto it = idx.find(need);
            if (it != idx.end()) {
                // it->second: need의 인덱스, i: 현재 인덱스
                return {it->second, i};
            }
            idx[nums[i]] = i;
        }
        return {};
    }
};