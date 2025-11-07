class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<pii>> gr(n);
        for(auto ed: edges) {
            int u = ed[0], v = ed[1], d = ed[2];
            gr[u].push_back({v, d});
            gr[v].push_back({u, d});
        }
        pq.push({0, 0});
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        while(!pq.empty()) {
            auto el = pq.top(); pq.pop();
            int time = el.first, node = el.second;
            if(time >= disappear[node] || time > ans[node]) continue;
            ans[node] = min(ans[node], time);
            for(auto nei: gr[node]) {
                int next_node = nei.first, dist = nei.second;
                if(time + dist < disappear[next_node] && time+dist < ans[next_node]) {
                    ans[next_node] = time+dist;
                    pq.push({time+dist, next_node});
                }
            }
        }

        for(int i = 0 ; i < n ; i++) if(ans[i] == INT_MAX) ans[i] = -1;
        return ans;
    }
};
