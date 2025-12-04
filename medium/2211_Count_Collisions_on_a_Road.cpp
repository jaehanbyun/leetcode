class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if (n == 1) return 0;

        int ans = 0;
        deque<char> d(directions.begin(), directions.end());
        
        while (d.front()=='L') {
            d.pop_front();        
        }

        while (d.back()=='R') {
            d.pop_back();
        }

        for (char c: d) {
            if (c != 'S') {
                ans++;
            }
        }

        return ans;
    }
};