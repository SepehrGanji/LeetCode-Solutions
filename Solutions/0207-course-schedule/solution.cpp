class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> g;
        vector<int> degree(n, 0);
        stack<int> st;
        for(int i = 0 ; i < n ; i++) g.push_back({});
        for(auto record: prerequisites) {
            // a -> b
            int b = record.at(0);
            int a = record.at(1);
            g[a].push_back(b);
            degree[b]++;
        }
        for(int i = 0 ; i < n ; i++) if(degree[i] == 0) st.push(i);
        int cnt = 0;
        while(!st.empty()) {
            cnt++;
            int curr = st.top(); st.pop();
            for(auto el: g[curr]) {
                if(--degree[el] == 0) st.push(el);
            }
        }

        return cnt == n;
    }
};
