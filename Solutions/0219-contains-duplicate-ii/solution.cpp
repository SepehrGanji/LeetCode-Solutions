class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k++;
        map<int, bool> mp;
        int n = nums.size();
        // window building
        for(int i = 0 ; i < min(k, n) ; i++) {
            int el = nums[i];
            if(mp[el] == true) return true;
            mp[el] = true;
        }
        // sliding the window
        for(int i = k ; i < n ; i++) {
            int el_to_add = nums[i];
            int el_to_remove = nums[i-k];
            mp[el_to_remove] = false;
            if(mp[el_to_add] == true) return true;
            mp[el_to_add] = true;
        }
        return false;
    }
};
