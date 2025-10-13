class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        bool noAnagrams = false;

        auto isAnagrams = [](string a, string b) -> bool {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a == b;
        };

        while (!noAnagrams) {
            int N = (int)words.size();

            if (N == 1) {
                break;
            }

            for (int i = 1; i < N; ++i) {
                bool ana = isAnagrams(words[i - 1], words[i]);
                if (ana) {
                    words.erase(words.begin() + i);
                    break;
                }
                if (i == N - 1) {
                    noAnagrams = true;
                    break;
                }
            }
        }

        return words;
    }
};