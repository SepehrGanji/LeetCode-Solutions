class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> gr;
        vector<bool> visited;
        for(int i = 0 ; i < n ; i++) {
            gr.push_back({});
            visited.push_back(false);
        }
        for(auto edge: edges) {
            int a = edge[0], b = edge[1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        queue<int> st;
        st.push(source);
        while(!st.empty()) {
            int top = st.front(); st.pop();
            if(!visited[top]) {
                visited[top] = true;
                if(top == destination) return true;
                for(auto v: gr[top]) {
                    st.push(v);
                }
            }
        }
        
        return false;
    }
};
