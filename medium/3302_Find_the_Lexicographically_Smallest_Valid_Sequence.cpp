class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j]:
        // word2[j:]를 정확히 맞출 때
        // word2[j]에 사용할 수 있는 가장 오른쪽 위치
        vector<int> last(m, -1);
        
        int j = m - 1;
        for (int i=n-1; i>=0&&j>=0; --i) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            } 
        }

        vector<int> answer;
        answer.reserve(m);

        bool canChange = true;
        j = 0;

        for (int i=0; i<n&&j<m; ++i) {
            if (word1[i] == word2[j]) {
                answer.push_back(i);
                ++j;
            } else if (canChange && (j == m-1 || i < last[j+1])) {
                answer.push_back(i);
                ++j;
                canChange = false;
            }
        }

        if (j != m) {
            return {};
        }

        return answer;
    }
};