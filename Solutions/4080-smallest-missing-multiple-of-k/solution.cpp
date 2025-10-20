class Solution {
public:
    bool find(vector<int>& nums, int n) {
        for(auto num: nums) if(num == n) return true;
        return false;
    }
    
    int missingMultiple(vector<int>& nums, int k) {
        int ka = k;
        while(1) {
            if(!find(nums, k)) return k;
            k += ka;
        }
    }
};
