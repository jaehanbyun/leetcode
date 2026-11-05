class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<bool> seen(amount + 1, false);
        queue<int> q;
        seen[0] = true;
        q.push(0);

        int res = 0;
        while (!q.empty()) {
            res++;

            int size = q.size();
            for (int i=0; i<size; ++i) {
                int cur = q.front();
                q.pop();

                for (int coin: coins) {
                    if (amount - coin < cur) continue;
                    int nxt = cur + coin;
                    if (nxt == amount) return res;
                    if (seen[nxt]) continue;
                    seen[nxt] = true;
                    q.push(nxt); 
                }
            }
        }

        return -1;
    }
};