class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        vector<int> prefixSum(n);
        
        prefixSum[0] = nums[0];
        for (int i=1; i<n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
    
        for (int i=1; i<n; ++i) {
            leftSum[i] = prefixSum[i] - nums[i];
        }

        for (int i=0; i<n; ++i) {
            rightSum[i] = prefixSum[n-1] - prefixSum[i];
        }

        vector<int> answer(n);
        for (int i=0; i<n; ++i) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }
        
        return answer;   
    }
};