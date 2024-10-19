class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        sort(points.begin(), points.end());
        int start = points[0][0], end = points[0][1];
        for(int i = 1 ; i < n ; i++) {
            int new_s = points[i][0], new_e = points[i][1];
            if(new_s > end) {
                ans++;
                start = new_s;
                end = new_e;
            } else {
                start = max(start, new_s);
                end = min(end, new_e);
            }
        }
        return ans;
    }
};
