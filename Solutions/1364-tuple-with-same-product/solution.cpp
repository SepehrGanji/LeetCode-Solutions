class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                int res = nums[i] * nums[j];
                mp[res]++;
            }
        }
        int ans = 0;
        for(auto el: mp) {
            int occ = el.second;
            if(occ > 1)
                ans += ((occ * (occ-1))/2) * 8;
        }
        return ans;
    }
};
