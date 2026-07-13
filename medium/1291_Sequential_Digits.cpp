class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> answer;

        for (int len=2; len<=9; ++len) {
            for (int l=0; l+len<=s.size(); ++l) {
                int num = stoi(s.substr(l, len));
                if (low <= num && num <= high) {
                    answer.push_back(num);
                }
            }
        }
        return answer;
    }
};