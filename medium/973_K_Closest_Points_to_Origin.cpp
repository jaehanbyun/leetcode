class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i=0; i<points.size(); ++i) {
            pair<int, int> item = {squaredDistance(points[i]), i};
            
            pq.push(item);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            res.push_back(points[idx]);
        }
        return res;
    }

private:
    int squaredDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};