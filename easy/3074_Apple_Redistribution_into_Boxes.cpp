class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m = capacity.size();
        int need = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        for (int i = 0; i < m; ++i) {
            need -= capacity[i];
            if (need <= 0) return i + 1;
        }
        
        return m;
    }
};

