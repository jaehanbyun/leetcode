class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> answer;
        int n = word.size();

        function<void(int, string, int)> backtrack = [&](int index, string current, int count) {
            if (index == n) {
                if (count > 0) current += to_string(count);
                answer.push_back(current);
                return;
            }

            backtrack(index+1, current, count+1);

            string next = current;
            if (count > 0) next += to_string(count);
            next += word[index];
            backtrack(index+1, next, 0);
        };

        backtrack(0, "", 0);

        return answer;
    }
};