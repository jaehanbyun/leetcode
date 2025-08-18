using namespace std;

class Solution {
public:
    unordered_set<string> makePow2Sigs() {
        unordered_set<string> S;
        for (int i = 0; i <= 30; ++i) {
            int p = 1 << i;             
            string s = to_string(p);
            sort(s.begin(), s.end());            
            S.insert(s);
        }
    return S;
    }
    bool reorderedPowerOf2(int n) {
        unordered_set<string> POW2_SIGS = makePow2Sigs();
        string t = to_string(n);
        sort(t.begin(), t.end());
        return POW2_SIGS.count(t) > 0;
    }
};