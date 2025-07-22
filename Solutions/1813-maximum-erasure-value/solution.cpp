class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = nums[0];
        int su = nums[0];
        int l = 0, r = 1;
        unordered_map<int, int> mp;
        mp[nums[0]] = 0;
        while(r < nums.size()) {
            // r is the next candidate
            int el = nums[r];
            if(mp.find(el) == mp.end() || mp[el] < l) {
                // does not exist
                mp[el] = r;
                su += el;
                ans = max(ans, su);
            } else {
                // be ga
                for(int i = l ; i < mp[el] ; i++) su -= nums[i];
                l = mp[el] + 1;
                mp[el] = r;
                ans = max(ans, su);
            }
            r++;
        }
        return ans;
    }
};
