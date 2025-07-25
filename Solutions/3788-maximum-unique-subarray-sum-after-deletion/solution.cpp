class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[n-1] < 0) return nums[n-1];
        set<int> st;
        for(auto num: nums) if(num >= 0) st.insert(num);
        int ans = 0;
        for(auto el: st) ans += el;
        return ans;
    }
};
