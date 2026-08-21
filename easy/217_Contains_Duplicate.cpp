class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto x: nums) {
            if (seen.contains(x)) return true;
            seen.insert(x);
        }
        return false;
    }
};