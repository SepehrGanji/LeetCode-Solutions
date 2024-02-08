class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
  vector<vector<pair<int , int>>> g(n);

  for(int i = 0 ; i < n ; i++) {
    int man = manager[i];
    if(man < 0) continue;
    // g[man][i] = informTime[man];
    g[man].push_back({i, informTime[man]});
  }

  queue<int> qu;
  qu.push(headID);
  vector<int> cost(n, 0);
  while(!qu.empty()) {
    int el = qu.front(); qu.pop();
    for(auto p: g[el]) {
      qu.push(p.first);
      cost[p.first] = cost[el] + p.second;
    }
  }

  int maxim = 0;
  for(int i = 0 ; i < n ; i++)
    if(cost[i] > maxim) maxim = cost[i];

  return maxim;
}
};
