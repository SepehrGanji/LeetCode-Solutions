class Solution {
public:

    void bfs(vector<int> adj[], int i, vector<int> &ans){
        ans[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(ans[it] == -1){
                    vector<int> col(5, 0);
                    for(auto k : adj[it]){
                        if(ans[k] != -1)
                            col[ans[k]] = 1;
                    }
                    for(int k = 1; k < 5; k++){
                        if(col[k] == 0){
                            ans[it] = k;
                            break;
                        }
                    }
                    q.push(it);
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n + 1];
        for(auto it : paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(n + 1, -1);
        for(int i = 1; i <= n; i++){
            if(ans[i] == -1){
                bfs(adj, i, ans);
            }
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};
