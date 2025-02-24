class Solution {
public:
    vector<vector<int>> gr;
    unordered_map<int, int> mp;
    vector<bool> visited;

    bool bobPath(int src, int time) {
        mp[src] = time;
        visited[src] = true;
        if(src == 0) return true;
        for(auto adj: gr[src]) {
            if(!visited[adj]) if(bobPath(adj, time+1)) return true;
        }
        mp.erase(src);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        gr.resize(n);
        visited.assign(n, false);
        for(auto ed: edges) {
            int a = ed[0], b = ed[1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        bobPath(bob, 0);
        visited.assign(n, false);
        queue<vector<int>> qq;
        // current, time, profit
        qq.push({0, 0, 0});
        int ans = INT_MIN;
        while(!qq.empty()) {
            auto mmd = qq.front(); qq.pop();
            int node = mmd[0], time = mmd[1], prof = mmd[2];
            visited[node] = true;
            if(mp.find(node) == mp.end() || mp[node] > time) {
                prof += amount[node];
            } else if(mp[node] == time) prof += (amount[node]/2);
            
            if(gr[node].size() == 1 && node != 0) ans = max(ans, prof);
            for(int adj: gr[node]) {
                if(!visited[adj]) qq.push({adj, time+1, prof});
            }
        }
        return ans;
    }
};
