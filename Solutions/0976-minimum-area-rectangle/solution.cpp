class Solution {
public:
    typedef pair<int, int> pii;
    int minAreaRect(vector<vector<int>>& points) {
        set<pii> st;
        unordered_map<int, vector<int>> xmap;
        for(auto &p : points) {
            pii point = pii(p[0], p[1]);
            st.insert(point);
            xmap[point.first].push_back(point.second);
        }
        int n = points.size();
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            for(int j = i + 1 ; j < n ; j++) {
                auto &p1 = points[i], &p2 = points[j];
                if(p1[1] == p2[1]) {
                    int x1 = p1[0], y1 = p1[1];
                    int x2 = p2[0], y2 = p2[1];
                    for(auto yay : xmap[x1]) {
                        if (yay == y1) continue;
                        pii x4 = pii(x2, yay);
                        if(st.find(x4) != st.end()) {
                            int local = abs(x2 - x1) * abs(yay - y1);
                            ans = min(ans, local);
                        }
                    }
                }
            }
        return ans == INT_MAX ? 0 : ans;
    }
};
