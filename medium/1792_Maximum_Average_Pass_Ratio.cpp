class Solution {
public:
    double gain(int p, int t) {
        return (double)(t - p) / ((double)t * (t + 1));
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double sumRatio = 0.0;
        priority_queue<tuple<double,int,int>> pq;

        for (auto& c: classes) {
            int p = c[0], t = c[1];
            sumRatio += (double)p / (double)t;
            pq.emplace(gain(p, t), p, t);
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [g, p, t] = pq.top(); pq.pop();
            sumRatio += g;        
            p = p + 1;
            t = t + 1;
            pq.emplace(gain(p, t), p, t); 
        }

        return sumRatio / n;
    }
};