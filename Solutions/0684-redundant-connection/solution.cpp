class Solution {
public:
    bool connected(int a, int b, vector<vector<int>> &gr) {
        stack<int> st;
        vector<bool> visited(1005, false);
        st.push(a);
        visited[a] = true;
        while(!st.empty()) {
            int node = st.top(); st.pop();
            if(node == b) return true;
            for(auto adj: gr[node]) {
                if(!visited[adj]) {
                    visited[adj] = true;
                    st.push(adj);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 1005;
        vector<vector<int>> gr(1005);
        vector<int> ans = {0, 0};
        for(auto ed: edges) {
            int a = ed[0], b = ed[1];
            if(connected(a, b, gr)) {
                ans[0] = a;
                ans[1] = b;
            }
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        return ans;
    }
};
