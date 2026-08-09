class Solution {
private:
    int n;
    vector<int> suffix;
    vector<vector<int>> memo;

    int dfs(int i, int M) {
        // 돌이 모두 사라진 경우
        if (i >= n) return 0;

        // 남은 돌을 모두 가져갈 수 있는 경우
        if (i+2*M >= n) return suffix[i];

        int& result = memo[i][M];

        if (result != -1) return result;

        result = 0;

        // X개를 가져가는 모든 경우 확인
        for (int X=1; X <= 2*M && i+X <= n; ++X) {
            int nextM = max(X, M);
            int currentScore = suffix[i] - dfs(i+X, nextM);
            
            result = max(result, currentScore);
        }

        return result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);

        for (int i=n-1; i>=0; --i) {
            suffix[i] = suffix[i+1] + piles[i];
        }
        
        memo.assign(n, vector<int>(n+1, -1));

        return dfs(0, 1);
    }
};