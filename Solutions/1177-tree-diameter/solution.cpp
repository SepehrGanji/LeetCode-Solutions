class Solution {
public:
    vector<vector<int>> gr;
    int n;

    pair<int, int> far(int node) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> qq;
        visited[node] = true;
        qq.push({node, 0});
        pair<int, int> ans = {node, 0};
        while(!qq.empty()) {
            auto el = qq.front(); qq.pop();
            int current_node = el.first, current_dist = el.second;
            if(ans.second < current_dist) {
                ans = el;
            }
            for(auto nei : gr[current_node]) {
                if(!visited[nei]) {
                    visited[nei] = true;
                    qq.push({nei, current_dist + 1});
                }
            }
        }
        // return (node, dist)
        return ans;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        n = edges.size() + 1;
        for(int i = 0 ; i < n ; i++) gr.push_back({});
        for(auto ed: edges) {
            int u = ed[0], v = ed[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        auto round1 = far(0);
        auto round2 = far(round1.first);
        return round2.second;
    }
};

