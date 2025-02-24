class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        vector<int> pfx(n, 0);
        vector<int> sfx(n, 0);
        pfx[0] = nums[0];
        for(int i = 1 ; i < n ; i++) if(nums[i] == 1) pfx[i] = pfx[i-1]+1;
        sfx[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--) if(nums[i] == 1) sfx[i] = sfx[i+1]+1;
        for(int i = 0 ; i < n ; i++) ans = max(ans, pfx[i]);
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 1) continue;
            int local_ans = 1;
            if(i > 0) local_ans += pfx[i-1];
            if(i < n-1) local_ans += sfx[i+1];
            ans = max(ans, local_ans);
        }
        return ans;
    }
};
