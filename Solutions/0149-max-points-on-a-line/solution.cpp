class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int ans = 2;
        for(int i = 0 ; i < n ; i++) {
            map<double, int> cnt;
            for(int j = 0 ; j < n ; j++) {
                if(i != j) cnt[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
            }
            for(auto el: cnt) {
                ans = max(ans, el.second+1);
            }
        }
        return ans;
    }
};
