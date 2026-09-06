class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> pair;
        for (int i=0; i<n; ++i) {
            pair.push_back({position[i], ((float)target - position[i]) / speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        
        vector<double> stack;
        for (int i=0; i<n; ++i) {
            stack.push_back(pair[i].second);
            if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
                stack.pop_back();
            }
        }

        return stack.size();
    }
};
