class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> g; vector<bool> visited;
        for(int i = 0 ; i < n ; i++) {
            visited.push_back(false);
            g.push_back({});
        }
        for(auto conn: connections) {
            int a = conn[0], b = conn[1];
            g[a].push_back(make_pair(b, true));
            g[b].push_back(make_pair(a, false));
        }
        int ans = 0;
        queue<int> dfs; dfs.push(0); visited[0] = true;
        while(!dfs.empty()) {
            int curr = dfs.front(); dfs.pop();
            for(auto nei: g[curr]) {
                if(!visited[nei.first]) {
                    dfs.push(nei.first);
                    visited[nei.first] = true;
                    if(nei.second == true) ans++;
                }
            }
            // only push when not visited
        }
        return ans;
    }
};
