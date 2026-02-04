class Solution {
public:    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        unordered_set<int> seen;
        vector<vector<int>> adj;
        for(int i = 0 ; i < n ; i++) adj.push_back({});
        for(auto ed: edges) {
            int u = ed[0], v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        stack<int> st;
        st.push(0);
        seen.insert(0);
        while(!st.empty()) {
            int el = st.top(); st.pop();
            for(auto nei : adj[el]) {
                if(seen.find(nei) != seen.end()) continue;
                seen.insert(nei);
                st.push(nei);
            }
        }
        return seen.size() == n;
    }
};
