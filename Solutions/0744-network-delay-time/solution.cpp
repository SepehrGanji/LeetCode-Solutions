class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  k--;
  // adjacency list
  vector<vector<pair<int, int>>> g(n);
  vector<bool> visited(n, false);
  for(auto e: times) {
    int a = e[0] - 1;
    int b = e[1] - 1;
    int w = e[2];
    g[a].push_back({b, w});
  }

  vector<int> dv(n, INT_MAX);
  visited[k] = true;
  dv[k] = 0;
  for(auto el: g[k]) {
    int b = el.first, w = el.second;
    dv[b] = w;
  }

  while(1) {
    int mini = INT_MAX;
    int miniel = -1;
    for(int el = 0 ; el < dv.size() ; el++) {
      if(visited[el] == false && dv[el] < mini) {
        mini = dv[el];
        miniel = el;
      }
    }
    if(miniel == -1) break;

    // now we have the minimum distance, so update!
    visited[miniel] = true;
    for(auto el: g[miniel]) {
      int b = el.first, w = el.second;
      if(!visited[b] && dv[miniel] + w < dv[b]) {
        dv[b] = dv[miniel] + w;
      }
    }
  }

  int maxim = -1;
  for(auto el: dv) {
    if(el > maxim) maxim = el;
  }
  return maxim == INT_MAX ? -1 : maxim;
}
};
