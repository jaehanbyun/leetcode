class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> freq(n);
        int commonCnt = 0;

        for (int i=0; i<n; ++i) {
            freq[A[i]-1]++;
            if (freq[A[i]-1] == 2) commonCnt++;

            freq[B[i]-1]++;
            if (freq[B[i]-1] == 2) commonCnt++;        

            C[i] = commonCnt;
        }

        return C;
    }
};
