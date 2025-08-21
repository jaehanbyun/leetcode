class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                height[j] = (mat[i][j] == 0) ? 0 : height[j] + 1;
            }

            int acc = 0;
            stack<pair<int,int>> st;

            for (int j = 0; j < n; ++j) {
                int h = height[j];
                int w = 1;

                while (!st.empty() && st.top().first >= h) {
                    acc -= st.top().first * st.top().second; 
                    w += st.top().second; 
                    st.pop();
                }

                if (h > 0) {
                    st.push({h, w});
                    acc += h * w; 
                }

                ans += acc; 
            }
        }
        return ans;
    }
};
