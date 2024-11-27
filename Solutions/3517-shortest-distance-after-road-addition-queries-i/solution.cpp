class Solution {
public:
    int solve(vector<vector<int>> &gr) {
        int n = gr.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> qu;
        qu.push(make_pair(0, 0));
        while(!qu.empty()) {
            auto el = qu.front(); qu.pop();
            int node = el.first, dist = el.second;
            if(node == n-1) return dist;
            for(auto nei: gr[node]) {
                if(!visited[nei]) {
                    qu.push(make_pair(nei, dist+1));
                    visited[nei] = true;
                }
            }
        }
        return n-1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> gr;
        for(int i = 0 ; i < n ; i++) gr.push_back({});
        for(int i = 0 ; i < n-1 ; i++) gr[i].push_back(i+1);
        for(auto qu: queries) {
            int a = qu[0], b = qu[1];
            gr[a].push_back(b);
            ans.push_back(solve(gr));
        }
        return ans;
    }
};
