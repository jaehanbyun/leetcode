class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> visited(26);
        vector<int> cnt(26);
        
        for (char c: s) {
            cnt[c-'a']++;
        }

        string stack;
        for (char c: s) {
            if (!visited[c-'a']) {
                while (!stack.empty() && stack.back()>c) {
                    if (cnt[stack.back()-'a']>0) {
                        visited[stack.back()-'a'] = 0;
                        stack.pop_back();
                    } else {
                        break;
                    }
                }
                visited[c-'a'] = 1;
                stack.push_back(c);
            }
            cnt[c-'a'] -= 1;
        }
        return stack;
    }
};