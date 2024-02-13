class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  // Edge list
  vector<int> distances(n+1, INT_MAX);
  distances[k] = 0;
  int iter = n - 1;
  while(iter--) {
    bool ch = false;
    for(auto el: times) {
      int a = el[0], b = el[1], w = el[2];
      if(distances[a] < INT_MAX && distances[a] + w < distances[b]) {
        distances[b] = distances[a] + w;
        ch = true;
      }
    }
    if(!ch) break;
  }
  int maxim = -1;
  for(int i = 1 ; i <= n ; i++) {
    if(distances[i] > maxim) maxim = distances[i];
  }
  return maxim < INT_MAX ? maxim : -1;
}
};
