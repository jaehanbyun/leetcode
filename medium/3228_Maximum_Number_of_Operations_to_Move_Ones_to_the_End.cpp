class Solution {
public:
    int maxOperations(string s) {
        int n = (int)s.size();
        int answer = 0;
        int cnt = 0;
        for (int i = n - 1; i >= 0;) {
            if (s[i] == '1') {
                answer += cnt;
                i--;
            }
            else {
                cnt++;
                while (i >= 0 && s[i] == '0') {
                    i--;
                }
            }
        }
        
        return answer;
    }
};