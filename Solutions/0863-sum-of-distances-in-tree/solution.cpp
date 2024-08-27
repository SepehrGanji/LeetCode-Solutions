class Solution {
public:
    vector<vector<int> > gr;
vector<int> ans;
vector<int> dp;
vector<bool> seen;
vector<int> sizeee;

void calc_dp(int root) {
    int ans = 0;
    int sii = 1;
    for(auto child: gr[root]) {
        if(!seen[child]) {
            seen[child] = true;
            calc_dp(child);
            ans += (dp[child] + sizeee[child]);
            sii += sizeee[child];
        }
    }
    dp[root] = ans;
    sizeee[root] = sii;
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int> >& edges) {
    gr.clear(); ans.clear(); dp.clear();
    vector<int> emp;
    for(int i = 0 ; i < n ; i++) {
        gr.push_back(emp);
        ans.push_back(-1);
        dp.push_back(0);
        seen.push_back(false);
        sizeee.push_back(0);
    }
    for(auto edge: edges) {
        int u = edge[0], v = edge[1];
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    seen[0] = true;
    calc_dp(0);
    ans[0] = dp[0];
    stack<int> q; q.push(0);
    while(!q.empty()) {
        int dad = q.top(); q.pop();
        for(auto child: gr[dad]) {
            if(ans[child] > -1) continue;
            int dad_dp = ans[dad];
            int dad_size = n;
            dad_dp -= (dp[child] + sizeee[child]);
            dad_size -= sizeee[child];
            int my_ans = dp[child] + dad_dp + dad_size;
            ans[child] = my_ans;
            q.push(child);
        }
    }
    //FOR(i, 0, n) cout << ans[i] << ' ';
    //cout << endl;
    return ans;
}
};
