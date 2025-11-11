class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      // a b c
      int a = 0, b = 0;
      for(int i = 2 ; i <= n ; i++) {
        int tmp = min(b + cost[i-1], a + cost[i-2]);
        a = b;
        b = tmp;
      }
      return b;
    }
};
