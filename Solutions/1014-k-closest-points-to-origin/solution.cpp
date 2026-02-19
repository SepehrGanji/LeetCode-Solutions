class Solution {
public:
    int dist(int a, int b) {
        return (a * a) + (b * b);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(auto point: points) {
            int x = point[0], y = point[1];
            int d = dist(x, y);
            pq.push({d, {x, y}});
        }
        vector<vector<int>> ans;
        while(k--) {
            auto el = pq.top(); pq.pop();
            ans.push_back({el.second.first, el.second.second});
        }
        return ans;
    }
};
