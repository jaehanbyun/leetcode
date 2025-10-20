class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        string availableOp[4] = {"++X", "X++", "--X", "X--"};
        unordered_map<string, int> m;

        for (string op: availableOp) {
            if (op[1] == '+') {
                m[op] = 1;
            }
            if (op[1] == '-') {
                m[op] = -1;
            }
        }
        
        int ans = 0;
        for (string o: operations) {
            ans += m[o];
        }

        return ans;
    }
};