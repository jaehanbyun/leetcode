class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector<int> freq(n, 0);
        vector<int> ans;
        ans.reserve(2);

        for (int x : nums) {
            freq[x] += 1;
            if (freq[x] == 2) {
                ans.push_back(x);
                if (ans.size() == 2) break; 
            }
        }
        return ans;
    }
};