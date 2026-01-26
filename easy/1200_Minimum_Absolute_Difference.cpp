class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minAbsDiff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; ++i) {
            minAbsDiff = min(minAbsDiff, arr[i+1] - arr[i]);
        }
        vector<vector<int>> output;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i+1] - arr[i] == minAbsDiff) {
                output.push_back({arr[i], arr[i+1]});
            }
        }
        return output;
    }
};