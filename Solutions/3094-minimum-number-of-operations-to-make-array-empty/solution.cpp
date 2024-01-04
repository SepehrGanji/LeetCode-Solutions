class Solution {
public:
int minOperations(vector<int>& nums) {
  map<int, int> mp;
  for(auto num: nums) {
    mp[num]++;
  }

  int ans = 0;
  for(auto num: mp) {
    int el = num.second;
    if(el == 1) return -1;
    if(el % 3 == 0) {
      ans += (el / 3);
      // ans += min(el/2, (el / 3) + (el % 3));
    } else if(el % 2 == 0) {
      ans += min(el / 2, (el / 3) + 1);
    } else {
      ans += (el / 3) + 1;
    }
  }
  return ans;
}
};
