class Solution {
public:
    vector<int> visited;
    int label;
    vector<int> order;
    
    void DFS(vector<vector<int>> &g, int s) {
        visited[s] = true;
        for(auto nei: g[s]) {
            if(!visited[nei]) DFS(g, nei);
        }
        order[s] = label--;
    }
    
    bool cycle(vector<vector<int>>& g, int n) {
        vector<int> color(n, 0);

        for (int start = 0; start < n; start++) {
            if (color[start] != 0) continue;

            stack<int> st;
            st.push(start);

            while (!st.empty()) {
                int node = st.top();

                if (color[node] == 0) {
                    color[node] = 1; 
                    for (int neighbor : g[node]) {
                        if (color[neighbor] == 1) {
                            return true;
                        }
                        if (color[neighbor] == 0) {
                            st.push(neighbor);
                        }
                    }
                } else {
                    color[node] = 2;
                    st.pop();
                }
            }
        }

        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> g(n);
        for(auto pa: prerequisites) {
            g[pa[1]].push_back(pa[0]);
        }
        // global vars
        for(int i = 0 ; i < n ; i++) {
            visited.push_back(false);
            order.push_back(-1);
        }
        label = n-1;
        // start
        for(int i = 0 ; i < n ; i++) {
            if(!visited[i]) DFS(g, i);
        }
        // compute ans
        vector<int> ans; 
        if(cycle(g, n)) return ans;
        for(int i = 0 ; i < n ; i++) ans.push_back(-1);
        for(int i = 0 ; i < n ; i++) ans[order[i]] = i;
        return ans;
    }
};
