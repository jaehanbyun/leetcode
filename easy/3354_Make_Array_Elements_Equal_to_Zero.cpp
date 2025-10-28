class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> startIdx;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) startIdx.push_back(i);
        }
        int dx[] = {1, -1};
        int ans = 0;
        for (int s: startIdx) {
            // move right if d = 0, move left if d = 1
            for (int d = 0; d <= 1; ++d) {
                vector<int> tmp = nums;
                int nowD = d;
                int idx = s;
                while (0 <= idx && idx < n) {
                    if (tmp[idx] == 0) {
                        idx += dx[nowD];
                    }
                    else {
                        tmp[idx] -= 1;
                        nowD = (nowD + 1) % 2;
                        idx += dx[nowD];
                    }
                }
                if (count(tmp.begin(), tmp.end(), 0) == n) ans += 1;
            }
        }
        return ans;
    }
};

