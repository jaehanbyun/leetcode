class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> counts(n+1, 0);

        for (int x: arr) {
            counts[min(x, n)]++;
        } 

        int ans = 1;
        for (int num=2; num<=n; ++num) {
            ans = min(ans + counts[num], num);
        }
        
        return ans;
    }
};