class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for (int n: nums) {
            if (!s.count(n)) s.insert(n);
            else return n;
        }
        return 1;
    }
};