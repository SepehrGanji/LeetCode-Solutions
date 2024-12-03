class Solution {
public:
    typedef pair<int, int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n, false);
        vector<vector<pii>> gr(n);
        for(auto ed: times) {
            int u = ed[0], v = ed[1], w = ed[2];
            gr[u-1].push_back(pii(v-1, w));
        }
        int maxTime = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push(pii(0, k-1));
        while(!pq.empty()) {
            auto el = pq.top(); pq.pop();
            int t = el.first, node = el.second;
            if(visited[node]) continue;
            visited[node] = true;
            maxTime = max(maxTime, t);
            for(auto ed: gr[node]) {
                if(!visited[ed.first]) {
                    pq.push(pii(t + ed.second, ed.first));
                }
            }
        }
        for(int i = 0 ; i < n ; i++) if(visited[i] == false) return -1;
        return maxTime;
    }
};
