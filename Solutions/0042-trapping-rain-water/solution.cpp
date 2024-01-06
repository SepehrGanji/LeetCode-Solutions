class Solution {
public:
    int trap(vector<int>& height) {
  int p1 = 0;
  int p2 = height.size() - 1;
  int maxl = 0, maxr = 0, ans = 0;
  while(p1 < p2) {
    int ep1 = height[p1], ep2 = height[p2];
    if(ep1 <= ep2) {
      if(maxl <= ep1) {
        maxl = ep1;
      } else {
        ans += (maxl - ep1);
      }
      p1++;
    } else {
      if(maxr <= ep2) {
        maxr = ep2;
      } else {
        ans += (maxr - ep2);
      }
      p2--;
    }
  }
  return ans;
}
};
