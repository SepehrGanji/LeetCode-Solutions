class Solution {
public:
    typedef pair<int, int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> gr(n+1);
        for(auto el: times) {
            int u = el[0], v = el[1], w = el[2];
            gr[u].push_back(pii(v, w));
        }
        vector<bool> visited(n+1, false);
        set<pii> st;
        int ans = 0;
        st.insert(pii(0, k));
        // visited[k] = true;
        while(!st.empty()) {
            pii el = *st.begin();
            int time = el.first;
            int node = el.second;
            st.erase(st.begin());
            if(!visited[node]) {
                ans = max(ans, time);
                visited[node] = true;
                for(auto nei: gr[node]) {
                    if(!visited[nei.first]) st.insert(pii(time+nei.second, nei.first));
                }
            }
        }
        // for(int i = 1 ; i <= n ; i++)  {
        //     cout << "i: " << i << " && visited: " << visited[i] << endl;
        // }
        for(int i = 1 ; i <= n ; i++) if(!visited[i]) return -1;
        return ans;
    }
};
