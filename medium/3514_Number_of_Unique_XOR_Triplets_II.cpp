class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> preXOR(2048, false);
        for (int j=0; j<n; ++j) {
            for (int k=j; k<n; ++k) {
                preXOR[nums[j] ^ nums[k]] = true;
            }
        }

        vector<bool> seen(2048, false);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<2048; ++j) {
                if (preXOR[j]) seen[nums[i] ^ j] = true; 
            }
        }

        int count = 0;
        for (bool s: seen) {
            if (s) count++;
        }
        return count;
    }
}; 