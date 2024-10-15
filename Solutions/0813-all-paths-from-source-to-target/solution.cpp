class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        stack<vector<int>> st;
        st.push({0});
        while(!st.empty()) {
            auto top = st.top(); st.pop();
            int last_vertex = top[top.size()-1];
            if(last_vertex == n-1) {
                ans.push_back(top);
                continue;
            }
            for(auto v: graph[last_vertex]) {
                top.push_back(v);
                st.push(top);
                top.pop_back();
            }
        }
        return ans;
    }
};
